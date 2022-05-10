#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long num = get_long("Number: ");
    long num_two = num;
    int length;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    // Check length of num
    for (int i = 0; num_two > 0; i++)
    {
        num_two = num_two / 10;
        length = length + 1;
    }
    num_two = num;

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }


    for (int i = 0; num_two > 0; i++)
    {
        mod1 = num_two % 10;
        num_two = num_two / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = num_two % 10;
        num_two = num_two / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    total = sum1 + sum2;
    num_two = num;

    // Check Luhn Algoritm
    if (total % 10 == 0)
    {
        for (int i = 0; num_two > 100; i++)
        {
            num_two = num_two / 10;
        }
        if (num_two == 34 || num_two == 37)
        {
            printf("AMEX\n");
        }
        else if (num_two > 50 && num_two < 56)
        {
            printf("MASTERCARD\n");
        }
        else if ((num_two / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }

    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}