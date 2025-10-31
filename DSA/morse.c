#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MORSE_LEN 6

typedef struct Node
{
    char symbol;       // ký tự (A-Z, số, hoặc '\0')
    struct Node *dot;  // nhánh trái (.)
    struct Node *dash; // nhánh phải (-)
} node;

node *createNode (char symbol)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->symbol = symbol;
    newNode->dash = NULL;
    newNode->dot = NULL;
    return newNode;
}

void insert (node *root, const char *code, char symbol)
{
    node *curr = root;

    for (int i = 0; code[i] != '\0' ; i++)
    {
        if (code[i] == '.')
        {
            if (!curr->dot)
            {
                curr->dot = createNode('\0');
            }
            curr = curr->dot;
        }
        else if (code[i] == '-')
        {
            if (!curr->dash)
                curr->dash = createNode('\0');
            curr = curr->dash;
        }
    }
    curr->symbol = symbol;
}

const char *morseTable[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

const char *getMorse(char c)
{
    if (isalpha(c))
    {
        return morseTable[toupper(c) - 'A'];
    }
    return "";
}

char decode(node *root, const char *code)
{
    node *curr = root;
    for (int i = 0; code[i] != '\0' ; i++)
    {
        if (code[i] == '.')
            curr = curr->dot;
        else if (code[i] == '-')
            curr = curr->dash;
        
        if (!curr)
            return '?';
    }

    return curr->symbol ? curr->symbol : '?';
}

void createTree(node *root)
{
    for (int i = 0; i < sizeof(26); i++)
    {
        insert(root, morseTable[i], 'A' + i);
    }
}

void delTree(node *root)
{
    if (!root) return;
    delTree(root->dot);
    delTree(root->dash);
    free(root);
}

int main()
{
    // Tạo root
    node *root = createNode('\0');
    createTree(root);

    char text[] = "HELLO";
    printf("Encode \"%s\" sang Morse:\n", text);
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%s ", getMorse(text[i]));
    }
    printf("\n");

    return 0;
}