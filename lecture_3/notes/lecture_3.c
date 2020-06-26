#include <stdio.h>
#include <cs50.h>
#include <string.h>





// // New data type --> typedef struct --> a container that you can store multiple other datatypes
// // This typedef struct is for PART2 2: phonebook.c
// typedef struct
// {
//     string name;
//     string number;
// }
// person; // --> This is the name you give to the structure








// // Part 1: compare strings
// int main(void)
// {
//     string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

//     for (int i = 0; i < 4; i++)
//     {
//         if (strcmp(names[i], "EMMA") == 0) // Strcmp compares two strings and returns 0 if there is a match
//         {
//             printf("Found!\n");
//             return 0; // return 0 usually indicates that the function was successful and cuts out of the program
//         }

//     }
//     printf("Not Found!\n");
//     return 1; // return 1 indicates an unsuccessful function and cuts out of the program
// }






// // Part 2: phonebook.c
// int main(void)
// {
//     // string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
//     // string numbers[4] = {"351-854-5544", "405-652-9898", "408-452-6532", "510-625-4897"};

//     // updated below to use the typedef struct syntax --> (1) call the struct (2) name the array and size it
//     person people[4];

//     // you can then fill the array mentioned above using the typedef struct syntax, which looks like the below
//     people[0].name = "EMMA";
//     people[0].number = "351-854-5544";

//     people[1].name = "RODRIGO";
//     people[1].number = "405-652-9898";

//     people[2].name = "BRIAN";
//     people[2].number = "408-452-6532";

//     people[3].name = "DAVID";
//     people[3].number = "510-625-4897";

//     for (int i = 0; i < 4; i++)
//     {
//         // if (strcmp(names[i], "EMMA") == 0) --> updated to include typedef struct below
//         if (strcmp(people[i].name, "EMMA") == 0)
//         {
//             // This returns the number that is in the same indices as the "EMMA"
//             // printf("%s\n", numbers[i]); --> updated to include typedef struct below
//             printf("%s\n", people[i].number);
//             return 0;
//         }
//     }
//     printf("Not Found!\n");
//     return 0;
// }






// Part 3: Big O Notation of the for loops
// the loops is considered a (n-1) loop with a (n-2) nested loop
// The Big O notation is as follows
// top most loop --> (n-1)
// nested loop --> (n-2)
// algorithm used --> (n-1)*(n-2)
// --> n^2 - 2n - 1n + 2
// --> n^2 - 3n + 2
// --> Big O Notation takes the number that changes exponentially compared to the rest of the variables --> n^2 --> Also called as the "Dominant Factor"
// --> Big O Notation --> Answer = O(n^2)
// According to Big O Notation rankings, O(n^2) bubble sort is the slowest algorithm to solve this problem
// NOTE: Bubble Sort uses parallel swapping until everything is in order







// Part 4: Selection Sort --> Finding a faster Big O
// Finding the smallest element and switching it with the first element of the list
// TIP: in coding language, the range of any list is always going to be from 0 to n-1
// For loop: for i from 0 to n-1
// --> find the smallest item between the ith item and the last element
// --> swap the smallest item with the ith item
// --> in this notation, n continually gets smaller as the list gets smaller with each iteration --> n-1, then n-2, then n-3 etc.
// --> n + (n-1) + (n-2) + ... + 1
// --> n(n+1)/2
// --> (n^2+n)/2
// --> n^2/2 + n/2
// --> O(n^2) --> This is also at the bottom of the Big O time complexity







// Part 5: Recursion --> implementing a code or function that calls itself
// iteration.c --> recursion.c

// // ----------iteration.c----------------
// void draw(int h);

// int main(void)
// {
//     int height = get_int("Height: ");

//     draw(height);
// }

// void draw(int h)
// {
//     for (int i = 1; i <= h; i++)
//     {
//         for (int j =1; j <= i; j++)
//         {
//             printf("#");
//         }
//         printf("\n");
//     }
// }

// -------------recursion.c---------------
void draw(int h);
int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int h)
{
    if (h == 0)
    {
        return; // to exit out of a loop or code, you can 'return'
    }

    draw(h-1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}


// Part 6: Merge Sort
// COntinual halving of an array to sort halves, then back track to the whole array by sorting 8,4,2,1,2,4,8
