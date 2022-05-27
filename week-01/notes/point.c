#include <stdio.h>
#include <cs50.h>

int main(void) {
int points = get_int("How many points did you loose? ")
const int MINE = 2;
if (points < MINE) {
    printf("You lost fewer points than me!\n");
} else if (points > MINE) {
    printf("You lost more points than me!\n");
} else {
    printf("You lost the same points as me!\n");
}
}