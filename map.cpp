/*  ___ map ___*/

#include <iostream>
#include <map>
using namespace std;

/**
 * map<key, value>
 * key là duy nhất
*/

int main()
{
    map<int,int> mp;

    mp.insert({1,2});
    mp.insert({3,4});
    mp.insert({5,6});
    mp.insert({7,8});

    mp[4] = 6;

    cout << mp[1] <<endl;

    /* for each*/
    for ( pair<int,int> x : mp)
    {
        cout << x.first << "  -- " <<x.second <<endl;
    }

    for (map<int,int>::iterator it = mp.begin(); it != mp.end() ; ++it)
    {
        cout<< (*it).first << ' ' << it->second << endl ;
    }

    return 0;
}