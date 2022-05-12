#include <cs50.h>
#include <stdio.h>
#include <string.h>

int string_length(string s);
int string_length2(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    int length2 = string_length2(name);
    int length3 = strlen(name);         // include <string.h>

    printf("%i\n", length);
    printf("%i\n", length2);
    printf("%i\n", length3);
}


int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
    
}
int string_length2(string s) // Min
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {}
    return i;
}