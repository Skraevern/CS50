#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Using ASCII. (google ASCII cs50)

int main(void)
{
    string s = get_string("Before:  ");
    printf("After:   ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else 
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    // Using ctype.h

    string s2 = s;
    printf("Before2: %s\n", s2);
    printf("After2:  ");
    for (int i = 0, n = strlen(s2); i < n; i++)
    {
        if (islower(s2[i]))
        {
            printf("%c", s2[i] - 32);
        }
        else 
        {
            printf("%c", s2[i]);
        }
    }
    printf("\n");

}

// Using ctype.h

