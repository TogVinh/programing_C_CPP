#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
            0 --- 1
          / |     | 
        /   |     3
       2    6  
       |\   | \
       |  \ |   \
       4    5     8
        \        /
         7 -----|
*/


int a[1001][1001];
std::vector<int> ke[1001];
bool visited[1001];
int node, edge;

// DFS in 
void DFS_AdjacencyList(int u)
{
    cout << u << " ";
    visited[u] = true;
    
    for (int v : ke[u])
    {
        if (!visited[v])
            DFS_AdjacencyList(v);
    }
}

void DFS_matrix(int u)
{
    cout << u << " "<<endl;
    visited[u] = true;
    
    for (int i = 0 ; i < node ; i++)
    {
        if (a[u][i] == 1)
        {
            if (!visited[i])
            {
                DFS_matrix(i);
            }
        }

    }
}

int main()
{
    #ifndef INPUT
        std::freopen("input.log", "r", stdin);
        std::freopen("output.log", "w", stdout);
    #endif

    // init with DFS_AdjacencyList
    cin >> node >> edge;
    cout << "node : " << node << " - edge : "<<edge<<endl;
    for (int i = 0 ; i < edge ; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    cout << "\n --- init finis ---\n";

    for (int i = 0; i < node; i++)
    {
        sort(ke[i].begin(), ke[i].end());
        cout << endl << i << " : ";
        for (int idx : ke[i])
        {
            cout << " -> " << idx; 
        }
    }
    cout <<endl;
    DFS_AdjacencyList(0);



    return 0;
}