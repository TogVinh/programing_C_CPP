#include <iostream>

using namespace std;

class SV {
    private:
        string ten, ngaysinh;
        double d1, d2, d3;
    
    public:

        void Nhap();
        void Xuat();
        friend void inthongtin(SV x);
};

void inthongtin(SV x){
    cout <<x.ten<<" "<<x.ngaysinh<<" "<<endl;
}

int main()
{
    SV x; // => Contructor


    return 0;
}