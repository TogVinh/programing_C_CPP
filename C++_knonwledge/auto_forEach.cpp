/**
 * từ C++ 11 -> tự động nhận dạng kiểu dữ liệu
 * Note :
 *      + cần khởi tạo giá trị cho biến khi khai bao biến nếu dùng auto
 *      + không dùng cho tham số hàm
 * 
 * >> Cú pháp trả về sau : 
 *  - có thể sử dụng để khai báo các hàm bằng cú pháp trả về theo sau
 *  - kiểu trả về đã cần phải được xác định trong nguyên mẫu hàm
*/

#include <iostream>

int main()
{
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
    {
       std::cout << number << ' ';
    }

    std::cout << '\n';

    return 0;
}