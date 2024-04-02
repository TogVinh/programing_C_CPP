#include <iostream>

using namespace std;

class SinhVien {
    private:
        string ten, ngaysinh, lop;
        double gpa;
    
    public:
        SinhVien(){
            cout<< "\n Default Contructor\n";
        }

        SinhVien(string ten, string ns, string LopHoc, double diem){
            this->ten = ten;
            ngaysinh = ns;
            lop = LopHoc;
            gpa = diem;
        }

        void nhapThongTin();
        void xuatThongTin();
        string getTen();
        void setTen(string newName);

        ~SinhVien(){
            cout<<"Destructor called\n";
        }
};
//Implementation
void SinhVien::nhapThongTin(){
    getline(cin,ten);
    cin>> ngaysinh>>lop>>gpa;
}

void SinhVien::xuatThongTin(){
    cout <<ten << " " << ngaysinh << " " <<lop <<" "<<gpa<<endl;
}

/* ----- Getter ----- */
string SinhVien::getTen(){
    return ten;
}


/* ----- Setter ----- */
void SinhVien::setTen(string newName){
    ten = newName;
}


int main()
{
    SinhVien x; // => Contructor
    x.nhapThongTin();
    x.xuatThongTin();
    x.setTen("test new name");
    x.getTen();



    return 0;
}