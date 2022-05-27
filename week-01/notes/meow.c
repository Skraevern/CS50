#include <stdio.h>

void meow(void) {
    printf("meow\n");
}

int main(void) {
    printf("Meow\n");
    printf("Meow\n");
    printf("Meow\n");
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
};
