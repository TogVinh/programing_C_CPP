#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* input file
6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R
*/

struct node
{
    int data;
    struct node *left;
    struct node *right;

    // contructor
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void makeChildNode(node *parent_node, int u, int v, char c)
{
    if (c=='L')
        parent_node->left = new node(v);
    else
        parent_node->right = new node(v);
}

void insertNode (node *Node, int u, int v, char c)
{
    if (Node == NULL)
        return;
    
    if (Node->data == u)
        makeChildNode(Node, u,v, c);
    else
    {
        insertNode(Node->left, u, v, c);
        insertNode(Node->right, u, v, c);

    }
}

void deleteTree(node *root)
{
    if (root == NULL)
        return;
    
    // Xóa cây con bên trái trước
    deleteTree(root->left);
    // Xóa cây con bên phải
    deleteTree(root->right);
    // Cuối cùng xóa node hiện tại
    cout << "Deleting node: " << root->data << endl;
    delete root;
}

int main()
{
#ifndef INPUT_MANUAL
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    node *root = NULL;
    // node *

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new node(u);
            makeChildNode(root, u,v,c);
        }
        else
            insertNode(root, u,v,c);
    }


    // Giải phóng bộ nhớ
    cout << "\nDeleting tree..." << endl;
    deleteTree(root);
    root = NULL; // Quan trọng: đặt con trỏ về NULL sau khi xóa

    delete root;
    return 0;
}