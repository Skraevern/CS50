#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    int height;
    int hash = 1;

    do
    {
        number = get_int("Height: ");
        height = number - 1;
    }
    while (number < 1 || number > 8);

    for (int i = 0; i < number; i++)
    {
        for (int in = 0; in < height; in++)
        {
            printf(" ");
        }
        height--;

        for (int ind = 0; ind < hash; ind++)
        {
            printf("#");
        }

        printf("  ");

        for (int ind = 0; ind < hash; ind++)
        {
            printf("#");
        }
        hash++;
        printf("\n");
    }
}