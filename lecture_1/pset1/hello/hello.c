// Import the dependencies / libraries needed for the program
#include <stdio.h>
#include <cs50.h>

// Begin the program using int-main-void
int main(void)
{
    // Grab a name from the user
    string name = get_string("What is your name?: ");
    // Return a greeting using the name given by the user
    printf("Hello, %s!\n", name);
}