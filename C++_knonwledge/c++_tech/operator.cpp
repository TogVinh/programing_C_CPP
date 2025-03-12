/*
    Kiểu_trả_về operator <toán tử> (danh_sách_đối_số)
    {
        //Định nghĩa toán tử
    }
*/

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(int ft, float in)
    {
        feet = ft;
        inches = in;
    }
    void getdist()
    {
        cout << "Enter feet : ";
        cin >> feet;
        cout << "Enter inches : ";
        cin >> inches;
    }
    void showdist()
    {
        cout << feet << "\' - " << inches << '\"';
    }
    Distance operator+(Distance d2)
    { // hàm nạp chồng toán tử

        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance(f, i);
    }
};
void main()
{
    Distance dist1, dist3, dist4;
    dist1.getdist();
    Distance dist2(11, 6.25);
    dist3 = dist1 + dist2;
    dist4 = dist1 + dist2 + dist3;
    // display all lengths
    cout << "dist1 = ";
    dist1.showdist();
    cout << endl;
    cout << "dist2 = ";
    dist2.showdist();
    cout << endl;
    cout << "dist3 = ";
    dist3.showdist();
    cout << endl;
    cout << "dist4 = ";
    dist4.showdist();
    cout << endl;
    system("pause");
}