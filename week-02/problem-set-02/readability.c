#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Calculates readability using Coleman-Liau index:
// index = 0.0588 * L - 0.296 * S - 15.8. 
// Where L = average nr. of letters and S = average number of sentences per 100

// The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29). And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57). Plugged into the Coleman-Liau formula, and rounded to the nearest integer, we get an answer of 3 (because 0.0588 * 464.29 - 0.296 * 28.57 - 15.8 = 3): so this passage is at a third-grade reading level.

int main(void)
{
    string input_txt = get_string("Text: ");
    printf("%s\n", input_txt);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(input_txt); i++)
    {
        int ascii = input_txt[i];
        
        if (ascii >= 97 && ascii <= 122 || ascii >= 65 && ascii <= 90)
        {
            letters++;
        }
        if (ascii == 33 || ascii >= 44 && ascii <= 46 || ascii >= 58 && ascii <= 63) 
        {
            sentences++;
            
        }
        if (ascii == 32) 
        {
            words++;
        }
        
    }
    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);
}