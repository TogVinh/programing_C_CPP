#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* ------- Adjacency List -------

Node 0: connect 1 -> 2 -> 3
Node 1: connect 0 -> 4 -> 5
Node 2: connect 0 -> 6 -> 7
Node 3: connect 0 -> 8 -> 9
Node 4: connect 1 -> 6 -> 9
Node 5: connect 1 -> 7
Node 6: connect 2 -> 4 -> 8
Node 7: connect 2 -> 5 -> 9
Node 8: connect 3 -> 6 -> 9
Node 9: connect 3 -> 4 -> 7 -> 8

---- input
10 15
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 8
3 9
4 6
5 7
6 8
7 9
8 9
4 9
----
=======================================*/

const int MAX = 1001;

/* Define Data Structure*/
vector<int> adj[MAX]; // Adjacency List
bool visited[MAX];
int parent[MAX];

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
    memset(parent, -1, sizeof(parent));
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int child : adj[current])
        {
            if (!visited[child])
            {
                q.push(child);
                parent[child] = current;
                visited[child] = true;
            }
        }
    }
    cout << endl;
}

void DFS(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (int currNode : adj[node])
    {
        if (!visited[currNode])
        {
            parent[currNode] = node;
            DFS(currNode);
        }
    }
    // cout << "\n";
}

void displayGraph()
{
    cout << "\nGraph representation (Adjacency List):\n";
    for (int i = 0; i < node; i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j];
            if (j < adj[i].size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }
}

void path(int s, int t)
{
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cout << "\nDFS : ";
    DFS(s);
    cout << endl << "Finish DFS === \n";
    if (!visited[t])
    {
        cout << "No path from node " << s << "to node " << t << endl;
        return;
    }

    vector<int> res;
    for (int idx = 0 ; idx < node ; idx++)
        cout << "parent["<<idx<<"] : "<< parent[idx] <<endl;
    cout << endl;

    while (t != s)
    {
        cout << "t = " << t << " | parent[t] " << parent[t] << endl;
        res.push_back(t);
        t = parent[t];
    }
    res.push_back(s);
    reverse(res.begin(), res.end());
    cout << "path : ";
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

void findConnectedComponents()
{
    memset(visited, false, sizeof(visited));
    int components = 0;

    cout << "\nConnected Components:\n";
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            components++;
            cout << "Component " << components << ": ";

            // BFS for this component
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int current = q.front();
                q.pop();
                cout << current << " ";

                for (int child : adj[current])
                {
                    if (!visited[child])
                    {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
            cout << endl;
        }
    }
    cout << "Total connected components: " << components << endl;
}

int main()
{
#if 1
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << "=== find path ===\n\n";

    cout << "Init Adjacency List\n";
    initAdjList();
    cout << "\n";

    cout << "Display Graph \n";
    displayGraph();

    // Test path finding
    cout << "\n=== PATH FINDING ===\n";
    // path(0, 9);
    path(1, 8);
    path(5, 3);

    // Find connected components
    // findConnectedComponents();

    return 0;
}