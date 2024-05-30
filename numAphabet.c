#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct alphabetNum
{
    int num;
    char low_letter;
    char up_letter;
} wNum;

wNum letter[27] = {0};

void fill()
{
    letter[0].num = 0;
    letter[0].low_letter = ' ';
    letter[0].up_letter = ' ';
    for (int i = 1; i < 27; i++)
    {
        letter[i].num = i;
        letter[i].low_letter = i + 96;
        letter[i].up_letter = i + 64;
    }
}

char *alphabet_position(const char *text)
{

    char *value = (char *)malloc(512 * sizeof(char));
    if (value == NULL)
    {
        return NULL;
    }

    char let = '\0';
    char current[5] = {0};
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isalpha(text[i]))
        {
            continue;
        }

        let = tolower(text[i]);
        // printf("let |%c|\n", let);
        for (int j = 1; j < 27; j++)
        {
            /* code */
            if (let == letter[j].low_letter)
            {
                sprintf(current, "%d ", letter[j].num);
                strcat(value, current);
                break;
            }
        }
    }
    // value[50] = '\0';
    int len = strlen(value);
    if (len > 0 && value[len - 1] == ' ')
    {
        value[len - 1] = '\0';
    }
    return value;
}

char *alphabet_position(char *text)
{
    char *ret = calloc(sizeof(char), strlen(text) * 2 + 1);
    int i = -1;
    int j = 0;

    while (text[++i])
        if (isalpha(text[i]))
            j += sprintf(&ret[j], "%d ", tolower(text[i]) - 96);
    ret[j - 1] = '\0';
    return (ret);
}

int main()
{
    fill();

    char *result = alphabet_position("The sunset sets at twelve o' clock.");
    if (result != NULL)
    {
        printf("Result: |%s|\n", result);
        free(result);
    }
    return 0;
}