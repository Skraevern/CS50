#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Calculates readability using Coleman-Liau index:
// index = 0.0588 * L - 0.296 * S - 15.8. 
// Where L = average nr. of letters and S = average number of sentences per 100

// The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29). And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57). Plugged into the Coleman-Liau formula, and rounded to the nearest integer, we get an answer of 3 (because 0.0588 * 464.29 - 0.296 * 28.57 - 15.8 = 3): so this passage is at a third-grade reading level.

int main(void)
{
    string input_txt = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentences = 0;

    for (int i = 0; i < strlen(input_txt); i++)
    {
        int ascii = input_txt[i];
        
        if (ascii >= 97 && ascii <= 122 || ascii >= 65 && ascii <= 90)
        {
            letters++;
        }
        if (ascii == 33 || ascii == 46 || ascii >= 58 && ascii <= 63) 
        {
            sentences++;
            
        }
        if (ascii == 32) 
        {
            words++;
        }
        
    }

    float L = letters / words * 100;
    float S = sentences / words * 100;

    float coleman_Liau = 0.0588 * L - 0.296 * S - 15.8;
    int coleman_Liau_round = round(coleman_Liau);
    

    printf("letters: %f\n", letters);
    printf("words: %f\n", words);
    printf("sentences: %f\n", sentences);
    printf("coleman_Liau: %f\n", coleman_Liau);
    printf("coleman_Liau_round: %i\n", coleman_Liau_round);

    if (coleman_Liau >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (coleman_Liau < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", coleman_Liau_round);
    }
}