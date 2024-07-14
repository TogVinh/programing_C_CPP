#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    /* Allocate the new node*/
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* Put in the data */
    new_node->data = new_data;

    /* Make next of new node ad head */
    new_node->next = (*head_ref);

    /*move the head to point to the new node*/
    (*head_ref) = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

int main()
{
    return 0;
}