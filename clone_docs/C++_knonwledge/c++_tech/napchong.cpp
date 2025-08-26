#include <iostream>

using namespace std;

class SV {
    private:
        string name, ngaysinh;
        double d1, d2, d3;
    
    public:

        friend istream& operator >> (istream &in, SV &x){
            getline(in, x.name);
            in >> x.ngaysinh>> x.d1 >> x.d2 >>x.d3;
            return in;
        }
};


int main()
{
    SV x; // => Contructor


    return 0;
}