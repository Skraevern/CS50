
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void) 
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

                            // s: hi!
    printf("s: %s\n", s);   // s: Hi!
    printf("t: %s\n", t);   // t: Hi!

    
    
    char *s2 = get_string("s2: ");
    
    char *t2 = malloc(strlen(s2) + 1);
    if (t2 == NULL)
    {
        return 1;
    }
    
    /*
    for (int i = 0; i < strlen(s2) + 1; i++)
    {
        t2[i] = s2[i];
    }
    */

    strcpy(t2, s2);

    t2[0] = toupper(t2[0]);

                             // s: hi!
    printf("s: %s\n", s2);   // s: hi!
    printf("t: %s\n", t2);   // t: Hi!

    free(t);
    return 0;
}