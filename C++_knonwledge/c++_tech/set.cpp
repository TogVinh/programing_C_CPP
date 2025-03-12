/*  __ Set __ */

#include <bits/stdc++.h>
using namespace std;

/**
 * set
 * multiset
 * unordered_set 
 * 
 * set<type> a
 * không tồn tại giá trị trùng
 * set.begin
 * set.end
 * set.find()
 *          set.find() = set.end => khong tim duoc
*/

int main()
{
    set<int> se;
    se.insert(1);
    se.insert(2);
    se.insert(1);
    se.insert(3);
    se.insert(4);
    se.insert(1);
    se.insert(5);

    /* for each*/
    for ( int x : se)
    {
        cout <<x <<" ";
    }

    /* using iterator*/
    for (set<int>::iterator it = se.begin() ; it != se.end() ; it++)
    {
        cout <<*it<< " ";
    }


    return 0;
}