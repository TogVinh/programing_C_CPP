#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> col; // col[i] = cột đặt hậu ở hàng i
int solutionCount = 0;

// Kiểm tra xem có thể đặt hậu tại (row, c)
bool isSafe(int row, int c)
{
    for (int i = 0; i < row; i++)
    {
        int prevC = col[i];
        if (prevC == c || abs(prevC - c) == abs(i - row))
            return false;
    }
    return true;
}

// Hàm quay lui
void solve(int row)
{
    if (row == N)
    {
        solutionCount++;
        // In ra một nghiệm
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << (col[i] == j ? "Q " : ". ");
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int c = 0; c < N; c++)
    {
        if (isSafe(row, c))
        {
            col[row] = c;
            solve(row + 1);
            // quay lui — không cần làm gì vì col[row] sẽ được ghi đè lần sau
        }
    }
}

int main()
{
    cout << "Nhap kich thuoc ban co N: ";
    cin >> N;
    col.resize(N);
    solve(0);
    cout << "Tong so nghiem tim duoc: " << solutionCount << "\n";
    return 0;
}
