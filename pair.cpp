#include <iostream>
using namespace std;

int main()
{
    pair <int , int> a;

    cin>>a.first;
    cin>>a.second;

    cout<<"first = "<<a.first<<endl;
    cout<<"Sencond = "<<a.second<<endl;

    pair<int, int> b = make_pair(2,200);

    pair<int, int> c = {104, 609};

    return 0;
}