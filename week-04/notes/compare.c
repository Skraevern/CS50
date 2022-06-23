#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same number\n");
    }
    else
    {
        printf("Different number\n");
    }

    string s = get_string("s: ");
    string t = get_string("t: ");
    printf("%p\n", s);              // 0x600002324010
    printf("%p\n", t);              // 0x600002324020

    // Does not work!
    if (s == t)
    {
        printf("Same string\n");
    }
    else
    {
        printf("Different string\n");
    }

    char *s2 = get_string("s2: ");
    char *t2 = get_string("t2: ");
    printf("%p\n", s2);             // 0x600002324030
    printf("%p\n", t2);             // 0x600002324040
    
    // Works!
        // Does not work!
    if (strcmp(s2, t2) == 0)
    {
        printf("Same string\n");
    }
    else
    {
        printf("Different string\n");
    }
}