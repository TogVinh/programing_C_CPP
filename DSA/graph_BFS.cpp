#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/* ------- Adjacency List -------
Node 1: connect 2 -> 3 -> 4
Node 2: connect 1 -> 5 -> 6
Node 3: connect 1 -> 7 -> 8
Node 4: connect 1 -> 9 -> 10
Node 5: connect 2 -> 7 -> 10
Node 6: connect 2 -> 8
Node 7: connect 3 -> 5 -> 9
Node 8: connect 3 -> 6 -> 10
Node 9: connect 4 -> 7 -> 10
Node 10: connect 4 -> 5 -> 8 -> 9

---- input
10 15
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
5 7
6 8
7 9
8 10
9 10
5 10
----
=======================================*/

/* ------- Adjacency Matrix (10 x 10) -------

     1  2  3  4  5  6  7  8  9 10
   _______________________________
1 |  0  1  1  1  0  0  0  0  0  0
2 |  1  0  0  0  1  1  0  0  0  0
3 |  1  0  0  0  0  0  1  1  0  0
4 |  1  0  0  0  0  0  0  0  1  1
5 |  0  1  0  0  0  0  1  0  0  1
6 |  0  1  0  0  0  0  0  1  0  0
7 |  0  0  1  0  1  0  0  0  1  0
8 |  0  0  1  0  0  1  0  0  0  1
9 |  0  0  0  1  0  0  1  0  0  1
10|  0  0  0  1  1  0  0  1  1  0

=======================================*/

/* ------- Edge List (15 edges total) -------
(1, 2)
(1, 3)
(1, 4)
(2, 5)
(2, 6)
(3, 7)
(3, 8)
(4, 9)
(4, 10)
(5, 7)
(5, 10)
(6, 8)
(7, 9)
(8, 10)
(9, 10)
=======================================*/


const int MAX = 1001;

/* Define Data Structure*/
vector<int> adj[MAX]; // Adjacency List
int matrix[MAX][MAX];            // Adjacency matrix
vector<pair<int, int>> edgeList; // Edge list
bool visited[MAX];

int node, edge;

// 1. Using Adjacency List
void initAdjList()
{
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Đồ thị vô hướng
    }
    memset(visited, false, sizeof(visited));
}

void BFS_AdjList(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

// 2. Using Adjacency Matrix
void initMatrix()
{
    cin >> node >> edge;
    memset(matrix, 0, sizeof(matrix));

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Đồ thị vô hướng
    }
    memset(visited, false, sizeof(visited));
}

void BFS_Matrix(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 1; i <= node; i++)
        {
            if (matrix[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// 3. Using Edge List
void initEdgeList()
{
    cin >> node >> edge;
    edgeList.clear();

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }
    memset(visited, false, sizeof(visited));
}

void BFS_EdgeList(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Tìm tất cả đỉnh kề thông qua danh sách cạnh
        for (auto edge : edgeList)
        {
            int u = edge.first, v = edge.second;

            if (u == current && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
            if (v == current && !visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
    cout << endl;
}

// Demo sử dụng
int main()
{
#if 1
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << "=== DEMO BFS VỚI CÁC CẤU TRÚC DỮ LIỆU KHÁC NHAU ===\n\n";

    cout << "1. SỬ DỤNG DANH SÁCH KỀ:\n";
    initAdjList();
    cout << "BFS từ đỉnh 1: ";
    BFS_AdjList(1);

    // cout << "\n2. SỬ DỤNG MA TRẬN KỀ:\n";
    // initMatrix();
    // memset(visited, false, sizeof(visited));
    // cout << "BFS từ đỉnh 1: ";
    // BFS_Matrix(1);

    // cout << "\n3. SỬ DỤNG DANH SÁCH CẠNH:\n";
    // initEdgeList();
    // memset(visited, false, sizeof(visited));
    // cout << "BFS từ đỉnh 1: ";
    // BFS_EdgeList(1);

    return 0;
}