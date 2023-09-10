#include <iostream>

using namespace std;

int func(int a)
{
    return a;
}

int funcA();
int funcB();
void funcC();
double funcD(int a);

int main()
{
    int (*fcnPtr)() = funcA(); // lỗi, không dùng dấu ngoặc đơn () sau tên hàm
    int (*fcnPtrA)() = funcA;  // ok, con trỏ fcnPtrA trỏ đến hàm funcA
    fcnPtrA = funcB;           // ok, fcnPtrA có thể trỏ đến một hàm khác có cùng cấu trúc
                               // fcnPtrA = &funcB; tương tự câu lệnh trên

    int (*fcnPtr1)() = funcA;       // ok
    void (*fcnPtr2)() = funcA;      // lỗi, kiểu trả về của con trỏ hàm và hàm không trùng nhau
    void (*fcnPtr3)() = funcC;      // ok
    double (*fcnPtr4)(int) = funcD; // ok

    return 0;
}