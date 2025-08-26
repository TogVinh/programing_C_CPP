#include <stdio.h>
#include <stdlib.h>

// don't specify what parameter to accept
typedef void (*print_callback)();

int add(int a, int b, print_callback print);
void console_print(int value);
void file_print(int value);
void print_hello();
void console_print_two_numbers(int value_one, int value_two);

int main(int argc, char *argv[])
{
    // print the output to console
    add(10, 20, console_print);

    // print the output to a file
    add(10, 20, file_print);

    // print just hello world inside add function
    add(10, 20, print_hello);

    // callback function that accepts two parameters
    add(10, 20, console_print_two_numbers);

    return 0;
}

int add(int a, int b, print_callback print)
{
    int sum = a + b;
    print(sum, -10);
    return sum;
}

void console_print(int value)
{
    printf("%d\n", value);
}

void file_print(int value)
{
    FILE *fp = fopen("/tmp/out.txt", "w");
    fprintf(fp, "%d", value);
    fclose(fp);
}

void print_hello()
{
    puts("Hello World");
}

void console_print_two_numbers(int value_one, int value_two)
{
    printf("Value one: %d, value twoo: %d\n", value_one, value_two);
}