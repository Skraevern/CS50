#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);      // 50
    int *p = &n;
    printf("p %p\n", p);      // p 0x16f73355c
    printf("&n %p\n", &n);     // &n 0x16f73355c
    printf("*p %i\n", *p);     // *p 50

    //string s = "HI!";
    char *s = "HI!";
    printf("s %s\n", s);       // s HI!
    //char *p2 = &s[0];
    //printf("*p2 %p\n", p2);     // *p2 0x1006cffac
    //printf("*p2 %p\n", s);      // *p2 0x1006cffac

    printf("s[0] %p\n", &s[0]); // s[0] 0x10269bf80
    printf("s[1] %p\n", &s[1]); // s[1] 0x10269bf81
    printf("s[2] %p\n", &s[2]); // s[2] 0x10269bf82
    printf("s[3] %p\n", &s[3]); // s[3] 0x10269bf83

    printf("s[0] %c\n", s[0]); // H
    printf("s[1] %c\n", s[1]); // I
    printf("s[2] %c\n", s[2]); // !
    printf("s[3] %c\n", s[3]); // 

    printf("*s       %c\n", *s);          // H
    printf("*(s + 1) %c\n", *(s + 1));   // I
    printf("*(s + 2) %c\n", *(s + 2));   // !
    printf("*(s + 3) %c\n", *(s + 3));   // 

    int numbers[] = {4, 6, 8, 2, 7, 5, 0};  
    printf("numbers[0] %i\n", numbers[0]);  // 4 
    printf("numbers[0] %i\n", numbers[1]);  // 6
    printf("numbers[0] %i\n", numbers[2]);  // 8

    printf("*numbers       %i\n", *numbers);        // 4 
    printf("*(numbers + 1) %i\n", *(numbers + 1));  // 6
    printf("*(numbers + 2) %i\n", *(numbers + 2));  // 8

}