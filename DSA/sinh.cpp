#include <iostream>
using namespace std;

int n, a[100], final = 0;

void ktao()
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

void sinh()
{
    int i = n - 1;
    while (i >= 0 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i < 0)
        final = 1;
    else
        a[i] = 1;
}

int main()
{
#ifndef INPUT
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    cin >> n;
    ktao();
    while (final == 0)
    {
        for (int idx = 0; idx < n; idx++)
            cout << a[idx];
        cout << endl;
        sinh();
    }
}
