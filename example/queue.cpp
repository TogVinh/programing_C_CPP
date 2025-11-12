#include <iostream>
#include <queue>

// 🧩 Hàm in queue<int> từ front -> back
void printQueue(std::queue<int> q) {
    std::cout << "[QUEUE] Front -> Back: ";
    while (!q.empty()) {
        std::cout << q.front();
        q.pop();
        if (!q.empty()) std::cout << " -> ";
    }
    std::cout << '\n';
}

int main() {
    std::queue<int> q;

    std::cout << "[LOG] Bat dau chuong trinh.\n";
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "[LOG] --- print queue ---\n";
    printQueue(q); // Gọi hàm in queue

    std::cout << "[LOG] --- Trang thai sau khi them ---\n";
    std::cout << "Front: " << q.front() << '\n';
    std::cout << "Back: " << q.back() << '\n';
    std::cout << "Size: " << q.size() << '\n';

    // Duyệt và loại bỏ phần tử
    std::cout << "[LOG] --- Bat dau lay tung phan tu trong queue ---\n";
    while (!q.empty()) {
        std::cout << "[LOG] Front hien tai = " << q.front() << " | Size = " << q.size() << '\n';
        std::cout << "Lay ra: " << q.front() << '\n';
        q.pop();
        std::cout << "[LOG] Da pop(). Size moi = " << q.size() << '\n';
        printQueue(q); // In lại hàng đợi sau mỗi pop
        std::cout << "------------------------------------\n";
    }

    std::cout << "\n[LOG] --- Ket thuc ---\n";
    std::cout << "Queue rong? " << (q.empty() ? "Yes" : "No") << '\n';
}
