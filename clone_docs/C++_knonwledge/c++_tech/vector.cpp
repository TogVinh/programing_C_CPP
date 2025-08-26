#include <iostream>
#include <vector>

using namespace std;

/**  vector<type> a;
 * start from 0
 * push_back(x)
 * a.begin() : iterator trỏ tới vị trí đầu tiên
 * a.end() : iterator trỏ tới vị trí n
 */

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    vector<int> a;
    a.push_back(100);
    a.push_back(200);

    cout << "size of vector a = |" << a.size() << "|" << endl;

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
    cout << "\n\n";

    cout<< "===== using for each \n";
    for (int j : a)
    {
        cout << j << " ";
    }
    cout << "\n\n";

    cout<< "===== using iterator  \n";
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << " ";

    cout <<"\n\n";

    /*vector b có sẵn 4 phẩn tử*/
    vector<int> b(4);
    cin >> b[2];

    /*vector c có 5 phần tử, mỗi phần tử có giá trị là 100*/
    vector<int> c(5, 100);

    return 0;
}