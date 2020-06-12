// Step 1: Import the dependencies
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Step 2: Declare a variable to store an integer prompted by the user
    int n;
    // Step 3: Use a do-while loop to cycle if user inputs a value out of range
    do
    {
        n = get_int("Please insert an integer between 1 and 8: ");
    }
    while (n < 1 || n > 8);

    // Step 4a: create a nested for loop. Outer loop indicates how many rows are created
    for (int i = 0; i < n; i++)
    {
        // Step 4b: the Inner loop indicates how many '#' is created in each row
        for (int j = 0; j < n; j++)
        {
            // Step 5: j will represent the columns. Create an if statement to print # or ''
            if (i + j >= n - 1)
                printf("#");
            else
                printf(" ");
            // IMPORTANT: the logic here is that "#" and spaces depend on whether the sum of row and col is >= n - 1
        }
        // Step 6: move to the next row
        printf("\n");
    }
}
