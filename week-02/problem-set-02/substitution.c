#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (argv[2] != NULL)
     {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];

    // Makes all key letters uppercase or returns if not a character.
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] <= 64 || key[i] >= 123)
        {
            printf("Invalid key. Must contain all letters.\n");
            return 1;
        }
        if (key[i] >= 97 && key[i] <= 122)
        {
            key[i] -= 32;
        }

    }
    // Checks for duplicate keys
    string temp_key = key;
    for (int i = 0; i < strlen(key) - 1; i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                printf("Invalid key. Duplicate keys.\n");
                return 1;
            }
        }

    }


    string text = get_string("plaintext: ");
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < strlen(upper_case); j++)
        {

            if (text[i] == upper_case[j])
            {
                text[i] = key[j];
                break;
            }

            if (text[i] == lower_case[j])
            {
                text[i] = key[j] + 32;
                break;
            }
        }
    }
    printf("ciphertext: %s\n", text);
    return 0;
}