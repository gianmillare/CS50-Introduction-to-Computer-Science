#include <stdio.h>
#include <cs50.h>

// Declare the functions used in the main program
void print(char c, int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Please enter a number between the numbers 1 and 8: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n - 1)
                printf("#");
            else
                printf(" ");
        }

        // The shape is divided by two spaces
        print(' ', 2);
        // Print the second half of the shape, which we know is i + 1
        print('#', i + 1);
        // Move to the next line / loop
        printf("\n");
    }
}

// Create a print function to print to make the second half of the shape easier
void print(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}