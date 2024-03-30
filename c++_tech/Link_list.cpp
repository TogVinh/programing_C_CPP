#include <iostream>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

typedef Node *node;

node newnode(int data)
{
    // Node *tmp = new Node()
    node tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

int Size(node head)
{
    int count = 0;
    while (head != NULL)
    {
        ++count;
        head = head->next;
    }

    return count;
}

void display(node head)
{
    cout << "List of Link List\n";
    while (head != NULL)
    {
        /* code */
        cout << head->data << " ";
        head = head->next;
    }
}

void themdau(node &head, int data)
{
    node moi = newnode(data);
    if (head == NULL)
    {
        head = moi;
    }
    else
    {
        // cap nhap tham chiiue
        moi->next = head;
        head = moi;
    }
}

void themcuoi(node &head, int data)
{
    node moi = newnode(data);
    if (head == NULL)
    {
        head = moi;
    }
    else
    {
        node tmp = head;
        while (tmp->next != NULL)
        {
            /* code */
            tmp = tmp->next;
        }
        tmp->next = moi;
    }
}

void themgiua(node &head, int data, int vitri)
{
    int n = Size(head);
    if (vitri < 1 || vitri > n + 1)
    {
        cout << "\n-- fail to insert --\n";
        return;
    }
}

int main()
{
    return 0;
}