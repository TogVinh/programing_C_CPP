/**
 * - Con trỏ như một trình lặp : hoạt động cho dữ liệu được lưu trữ
 * tuần tự trong bộ nhớ.
 */

#include <array>
#include <iostream>

int main()
{
    std::array data{0, 1, 2, 3, 4, 5, 6};

    auto begin{&data[0]};
    // note that this points to one spot beyond the last element
    auto end{begin + std::size(data)};

    // for-loop with pointer
    for (auto ptr{begin}; ptr != end; ++ptr) // ++ to move to next element
    {
        std::cout << *ptr << ' '; // Indirection to get value of current element
    }
    std::cout << '\n';

    return 0;
}

#include <iostream>
#include <vector>

int main()
{
    std::vector v{1, 2, 3, 4, 5, 6, 7};

    auto it{v.begin()};

    ++it;                     // move to second element
    std::cout << *it << '\n'; // ok: prints 2

    v.erase(it); // erase the element currently being iterated over

    // erase() invalidates iterators to the erased element (and subsequent elements)
    // so iterator "it" is now invalidated

    ++it;                     // undefined behavior
    std::cout << *it << '\n'; // undefined behavior

    return 0;
}