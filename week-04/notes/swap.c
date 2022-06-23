#include <stdio.h>

void not_working_swap_in_c (int a, int b); 
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);                      // 1 2
    not_working_swap_in_c(x, y);
    printf("x is %i, y is %i\n", x, y);                     // 1 2
    swap(&x, &y);
    printf("x final is %i, y final is %i\n", x, y);         // 2 1
}

void not_working_swap_in_c (int a, int b) 
{
    printf("a is %i, b is %i\n", a, b);                      // 1 2
    int tmp = a;
    a = b;
    b = tmp;
    printf("a is %i, b is %i\n", a, b);                     // 2 1
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}