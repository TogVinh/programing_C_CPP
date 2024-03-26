#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * getline(cin,s) : stop when meet "\n"
*/
int main()
{
    string s = "this is string";
    stringstream ss(s); // khoi tao ss =s

    string word;

    while (ss >> word)
    {
        cout <<word<<endl;
    }

    return 0;
}