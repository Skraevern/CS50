#include <stdio.h>
#include <cs50.h>

int main(void) {
    // Prompt user to agree
    char c = get_char("Do you agree? ")

    // CHeck whether user agrees
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n")
    }
    else if (c == 'n' || == 'N')
    {
        printf("Not agreed\n")
    }   
    else {
        printf("Wrong input. Use y or n")
    }
    
    
}