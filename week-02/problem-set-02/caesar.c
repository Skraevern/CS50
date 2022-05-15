#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argv[2] != NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    bool is_digit = only_digits(argv[1]);
    if (is_digit == 0)
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
            for (int in = 0; letter >= 122; in++)
            {
                letter = letter - 26;
            }
        }
        if (letter >= 65 && letter <= 90)
        {
        letter = text[i] + cypher;
        for (int ind = 0; letter >= 90; ind++)
            {
                letter = letter - 26;
            };
        }
        text[i] = letter;
    }
    printf("ciphertext: %s\n", text);
    return 0;
}


bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        int ascii = s[i];
        if (ascii < 48 || ascii > 57)
        {
            return false;
        }
    }
    return true;
}
