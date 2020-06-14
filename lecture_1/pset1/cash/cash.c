// import the dependencies
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        n = get_float("How much change is owed: ");
    }
    while (n <= 0);

    // Convert the dollar amount inputed to cents. i.e. $1.45 --> 145c
    // Round the cents using round ()
    int coins = round(n * 100);

    // Declare a counter (i.e. count) equal to 0, increment after every coin used
    int count = 0;

    // Declare a list for all denominations
    int deno[] = {25, 10, 5, 1};
    int size = sizeof(deno) / sizeof(int);

    // Write a for loop looping through all denominations as long as i is less than 4 (number of denominations)
    for (int i = 0; i < size; i++)
    {
        // First the loop will divide the total by 25, then 10, etc
        count += coins / deno[i];
        // After 'counting' how many denominations are needed, apply modulus to the total to get remaining total
        coins %= deno[i];
    }

    // move to the next line
    printf("%i\n", count);
}