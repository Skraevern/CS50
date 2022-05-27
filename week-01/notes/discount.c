#include <stdio.h>
#include <cs50.h>

float discount(float price, int percentage);

int main(void) {
    float regular = get_float("Regular price: ");
    int percent_of = get_int("Discount of: ")
    float sale = discount(regular, percent_of);

    printf("Sale price: %.2f\n", sale)
}

float discount(float price, int percentage) {
    return price * (100 - percentage) / 100;
}