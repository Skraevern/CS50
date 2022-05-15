#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s); 

int main(int argc, string argv[])
{   
    if (argv[1] != NULL || argv[2] == NULL)
    {
       return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(argv[1]) == true)
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int cypher = atoi(argv[1]);
    string text = get_string("plaintext:  ");
    int letter;
            
    for (int i = 0; i < strlen(text); i++)
    {
        letter = text[i];
        if (letter >= 97 && letter <= 122)
        {
            letter = text[i] + cypher;
            for (int i = 0; letter >= 122; i++)
            {
                letter = letter - 26;
            }
        }
        if (letter >= 65 && letter <= 90)
        {
            letter = text[i] + cypher;
            for (int i = 0; letter >= 90; i++)
            {
                letter = letter - 26;
            };
        }

        text[i] = letter;
    }
    printf("ciphertext: %s\n", text);
}


bool only_digits(string s) 
{
    int ascii = s[0];
    if (ascii >= 48 && ascii <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}
