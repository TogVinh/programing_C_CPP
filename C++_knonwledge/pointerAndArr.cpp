#include <iostream>

int main()
{
    // Tạo mảng số nguyên
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sử dụng con trỏ để in ra từng giá trị của mảng
    int *ptr = NULL;
    ptr = &arr[0];
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(ptr + i) << " ";
    }

    return 0;
}
