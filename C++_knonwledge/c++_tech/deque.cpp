/* ______Recursion_______ */

/**
 * Base case : bài toán con nhỏ nhất
 * công thức truy hồi
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int S(int n)
{
    if ( n == 1)
        return 1;
    else
        return n + S(n-1);
}

int main()
{


    return 0;
}