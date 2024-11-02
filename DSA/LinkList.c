#include <stdio.h>
#include <stdlib.h>

#define null NULL

typedef struct node
{
    /* data */
    int data;
    struct node *next;
} node;

node *makeNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = null;
    return newNode;
}

void printList(node *head)
{
    printf("\nhead --> ");
    while (head != null)
    {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("NULL \n");
}

int size(node *head)
{
    int count = 0;
    while (head != null)
    {
        count++;
        head = head->next;
    }
    return count;
}

void pushFront(node **head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head, int x)
{
    node *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    node *tmp = *head;
    while (tmp->next != null)
        tmp = tmp->next;
    tmp->next = newNode;
}

void insert(node **head, int data, int pos)
{
    int total = size(*head);
    if (pos < 0 || pos > total + 1)
    {
        printf("Fail to insert \n");
        return;
    }

    node *newNode = makeNode(data);

    if (pos == 1)
    {
        pushFront(head, data);
        return;
    }

    node *tmp = *head;

    /**
     * insert to node have number K
     * need to trave to node in position K-1
     * need K-2 step loop to traver to node have postion K-1
     */
    for (int i = 1; i <= (pos - 2); i++)
        tmp = tmp->next;

    newNode->next = tmp->next;
    tmp->next = newNode;
}

void popFront(node **head)
{
    if (*head == null)
        return;

    node *tmp = *head;
    *head = (*head)->next;

    free(tmp);
}

void popBack(node **head)
{
    int total = size(*head);
    if (*head == null)
        return;

    if((*head)->next == null)
    {
        free(*head);
        *head = null;
        return;
    }

    node *tmp = *head;
    while (tmp->next->next != null)
        tmp = tmp->next;

    free(tmp->next);
    tmp->next = null;
}

void delAtPosition(node **head, int pos)
{
    if(*head == null)
        return;

    if (pos == 1)
    {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    
}

int main()
{
    system("clear");
    node *head = null;
    int total = 0;

    printf("Before: \n");
    for (int i = 1; i < 6; i++)
    {
        // pushFront(&head, i);
        pushBack(&head, i);
    }
    total = size(head);
    printList(head);
    printf("\n Total : %d\n", total);

    printf("\n ..... Insert ..... \n");
    insert(&head, 9, 3);
    insert(&head, 0, 1);
    insert(&head, 6, (size(head) + 1));

    total = size(head);
    printList(head);
    printf("\n Total : %d\n", total);

    
    printf("\n ..... Pop Front ..... \n");
    popFront(&head);

    total = size(head);
    printList(head);
    printf("\n Total : %d\n", total);

    printf("\n ..... Pop Back ..... \n");
    popBack(&head);

    total = size(head);
    printList(head);
    printf("\n Total : %d\n", total);

    return 0;
}