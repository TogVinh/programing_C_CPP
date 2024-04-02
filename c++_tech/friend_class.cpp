#include <iostream>
using namespace std;

class MyClass1
{
private:
    int _privateProp;

public:
    MyClass1(int n)
    {
        this->_privateProp = n;
    }

    friend class MyClass2;
};

class MyClass2
{
private:
    int _privateProp;

public:
    MyClass2(int n)
    {
        this->_privateProp = n;
    }

    void myMethod(MyClass1 mClass)
    {
        cout << mClass._privateProp;
    }
};

int main()
{
    MyClass1 mClass1(2409);
    MyClass2 mClass2(2001);
    mClass2.myMethod(mClass1); // in ra màn hình 2409
    return 0;
}