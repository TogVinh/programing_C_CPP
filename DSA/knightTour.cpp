#include <bits/stdc++.h>
using namespace std;

int SIZE; // chessboard size SIZE x SIZE

// 8 legal moves of the knight
const int dx[8] = {2, 1, -1, -2, -2, -1,  1,  2};
const int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1};

// Check if cell (x,y) is valid and empty
bool isValid(int x, int y, const vector<vector<int>> &board)
{
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == -1;
}


void printBoard(const vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << setw(3) << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// hàm đệ quy quay lui: vị trí (x,y) đang là bước 'step'
bool knightTourUtil(int x, int y, int step, vector<vector<int>> &board)
{
    cout << "knightTourUtil ===> ENTER\n";
    if (step == SIZE * SIZE - 1)
    {
        // đã đi hết mọi ô, đánh dấu bước cuối (đã được đánh trước gọi), trả true
        return true;
    }

    // thử 8 hướng
    for (int k = 0; k < 8; ++k)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isValid(nx, ny, board))
        {
            board[nx][ny] = step + 1; // ghi bước tiếp theo
            if (knightTourUtil(nx, ny, step + 1, board))
                return true; // tìm thấy nghiệm, propagate true
            // backtrack
            board[nx][ny] = -1;
        }
    }
    return false; // không có đường đi tiếp dẫn đến nghiệm
}

// wrapper: khởi tạo board, bắt đầu từ (startX,startY)
bool knightTour(int startX, int startY)
{
    vector<vector<int>> board(SIZE, vector<int>(SIZE, -1));
    board[startX][startY] = 0; // bước đầu tiên (0)

    if (knightTourUtil(startX, startY, 0, board))
    {
        cout << "Found a Knight's tour (0-based step numbers):\n";
        printBoard(board);
        return true;
    }
    else
    {
        cout << "No solution found from start (" << startX << "," << startY << ").\n";
        return false;
    }
}

int main()
{
    /** ===================================
     * | Knight Tour using BackTracking 
     * ====================================*/
#ifndef INPUT
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    cout << "Nhap kich thuoc ban co SIZE (VD: 8): ";
    if (!(cin >> SIZE))
        return 0;
    int sx = 0, sy = 0;
    cout << "\nNhap vi tri bat dau startX startY (0-based, mac dinh 0 0): ";
    if (!(cin >> sx >> sy))
    {
        sx = 0;
        sy = 0;
    }
    // kiểm tra giá trị hợp lệ
    if (sx < 0 || sx >= SIZE || sy < 0 || sy >= SIZE)
    {
        cerr << "\nVi tri bat dau khong hop le!\n";
        return 0;
    }

    // chạy thuật toán
    knightTour(sx, sy);
    return 0;
}
