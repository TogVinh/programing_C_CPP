#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "json.hpp"

using json = nlohmann::json;
#define SOCKET_PATH "/tmp/ipc_socket"

void handle_request(int client_fd, json request)
{
    std::string type = request["type"];
    json response;

    if (type == "get")
    {
        std::string key = request["key"];
        response["status"] = "ok";
        response["value"] = "value_of_" + key;
    }
    else if (type == "set")
    {
        std::string key = request["key"];
        std::string value = request["value"];
        response["status"] = "ok";
        response["msg"] = "set " + key + " = " + value;
    }
    else if (type == "info_request")
    {
        std::string info = request["info"];
        response["status"] = "ok";
        response["result"] = "processed info " + info;
    }
    else
    {
        response["status"] = "error";
        response["msg"] = "unknown request type";
    }

    std::string data = response.dump();
    send(client_fd, data.c_str(), data.size(), 0);
}

void periodic_task(int client_fd)
{
    while (true)
    {
        json req;
        req["type"] = "info_request";
        req["info"] = "d";
        std::string msg = req.dump();
        send(client_fd, msg.c_str(), msg.size(), 0);
        sleep(5);

        req["info"] = "e";
        msg = req.dump();
        send(client_fd, msg.c_str(), msg.size(), 0);
        sleep(5);
    }
}

int main()
{
    unlink(SOCKET_PATH);
    int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    if (bind(server_fd, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        return 1;
    }

    std::cout << "[Server] Waiting for connection...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0)
    {
        perror("accept");
        return 1;
    }

    std::cout << "[Server] Client connected.\n";
    std::thread(periodic_task, client_fd).detach();

    char buffer[1024];
    while (true)
    {
        ssize_t bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0)
            break;
        buffer[bytes] = '\0';
        try
        {
            json req = json::parse(buffer);
            std::thread worker(handle_request, client_fd, req);
            worker.detach();
        }
        catch (...)
        {
            std::cerr << "[Server] Invalid JSON received.\n";
        }
    }

    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);
    return 0;
}
