#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "json.hpp"

using json = nlohmann::json;
#define SOCKET_PATH "/tmp/ipc_socket"

void handle_server_request(json req)
{
    std::string info = req["info"];
    std::cout << "[Client] Handling request from server: info=" << info << std::endl;
    sleep(2);
    std::cout << "[Client] Done processing info " << info << std::endl;
}

void listen_server(int sock)
{
    char buffer[1024];
    while (true)
    {
        ssize_t bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0)
            break;
        buffer[bytes] = '\0';
        try
        {
            json req = json::parse(buffer);
            if (req.contains("info"))
            {
                std::thread(handle_server_request, req).detach();
            }
            else
            {
                std::cout << "[Client] Server response: " << req.dump() << std::endl;
            }
        }
        catch (...)
        {
            std::cerr << "[Client] Invalid JSON received.\n";
        }
    }
}

int main()
{
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    if (connect(sock, (sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("connect");
        return 1;
    }

    std::cout << "[Client] Connected to server.\n";
    std::thread listener(listen_server, sock);
    listener.detach();

    while (true)
    {
        std::string cmd, key, value;
        std::cout << "Enter command (get/set/quit): ";
        std::cin >> cmd;
        if (cmd == "quit")
            break;

        json req;
        if (cmd == "get")
        {
            std::cout << "Key: ";
            std::cin >> key;
            req["type"] = "get";
            req["key"] = key;
        }
        else if (cmd == "set")
        {
            std::cout << "Key: ";
            std::cin >> key;
            std::cout << "Value: ";
            std::cin >> value;
            req["type"] = "set";
            req["key"] = key;
            req["value"] = value;
        }
        else
        {
            std::cout << "Unknown command\n";
            continue;
        }

        std::string data = req.dump();
        send(sock, data.c_str(), data.size(), 0);
    }

    close(sock);
    return 0;
}
