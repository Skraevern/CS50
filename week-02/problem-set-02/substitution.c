#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


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
    string lower_key;
    string text = get_string("plaintext: ");
    string text2 = text;
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    
    for (int i = 0; i < strlen(lower_case); i++)
    {
        
        //lower_key[i] = key[i] + 32;
    }
    

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
                text[i] = lower_key[j];
                break;
            }
        }
    }
    printf("ciphertext: %s\n", text);
    return 0;
}
//text2[i] = key[i_upper];