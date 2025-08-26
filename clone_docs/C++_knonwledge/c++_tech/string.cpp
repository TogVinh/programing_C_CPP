#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * getline(cin,s) : stop when meet "\n"
*/
int main()
{
    string s = "this is string";
    cout <<s<<endl;
    cout <<"size |" <<s.size()<<"|\n";

    // for (int i = 0 ; i < s.size(); i++)
    // {
    //     cout << s[i] <<endl;
    // }

    // for (char x : s)
    // {
    //     cout << x <<endl;
    // }

    for (string::iterator it = s.begin(); it != s.end() ; ++it)
    {
        cout << *it <<endl;
    }

    return 0;
}