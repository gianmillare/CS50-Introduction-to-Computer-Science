// Lecture 2 Notes
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// float average(int length, int array[]);

// Part 1: Debugging
// Tip: when you get an error in a program, the error is usually the first in the list of bugs
// For this class, running help50 to find the bug is recommended
// Example 1:
// int main(void)
// {
//     string name = get_string("What is your name? \n");
//     printf("Hello, %s!\n", name);
// }




// // Part 2: Introducing debug50, check50, and style50
// int main(void)
// {
//     // click to the left side of the line number to place a red mark on the code you want to test
//     // debug50 ./lecture_2
//     // click on 'debugger' on the right side
//     for (int i = 1; i <= 10; i++)
//     {
//         printf("# %i!\n", i);
//     }
// }

// Rubber Duck Debugging
// talking to a rubber duck as if you were speaking to a colleage in hopes of finding the problem in the code






// Part 3: Arrays

// int main(void)
// {
//     // Strings use double "", chars use single ''
//     char c1 = 'H';
//     char c2 = 'I';
//     char c3 = '!';
//     printf("%i %i %i\n", (int) c1, (int) c2, (int) c3);
// }

// const int N = 3; // This can be used to define a global variable that cannot be changed

// int main(void)
// {
//     int n = get_int("Number of scores: ");

//     int scores[n];

//     for (int i = 0; i < n; i++)
//     {
//         scores[i] = get_int("Score %i: ", i + 1);
//     }

//     printf("Average: %0.2f\n", average(n, scores));
// }


// // Function to get the average in the above main code
// float average(int length, int array[])
// {
//     int sum = 0;
//     for (int i = 0; i < length; i++)
//     {
//         sum += array[i];
//     }
//     return (float) sum / (float) length;
// }




// Part 4: Strings (are just an array of chars)
// Strings are as long as you need, so the amount of bytes used depends on the length of the string.
// A string that is length 3 takes as many as those characters used + 1 ("dog" has 4)

// int main(void)
// {
//     string names[4];

//     names[0] = "EMMA";
//     names[1] = "RODRIGO";
//     names[2] = "BRIAN";
//     names[3] = "DAVID";

//     printf("%s\n", names[0]);
//     // Characters in a string can then be indexed farther by indexing the name and then indexing the character
//     printf("%c%c%c%c\n", names[0][0], names[0][1], names[0][2], names[0][3]);
// }





// Part 5: Manipulating Strings using iteration

// int main(void)
// {
//     string s = get_string("Input: ");
//     printf("Output: ");


//     // for (int i = 0; s[i] != '\0'; i++)
//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         printf("%c", s[i]);
//     }
//     printf("\n");
// }






// Part 6: Uppercase a string
// int main(void)
// {
//     string s = get_string("Before: ");
//     printf("After: ");

//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         // this is using another dependency
//         printf("%c", toupper(s[i]));
//         // if (s[i] >= 'a' && s[i] <= 'z')
//         // {
//         //     // The difference between the uppercase and lowercase letters is 32 according to ASCII
//         //     printf("%c", s[i] - 32);
//         // }
//         // else
//         // {
//         //     printf("%c", s[i]);
//         // }
//     }
//     printf("\n");
// }




// Part 7: argc and argv
// This function takes in arguments WHEN you call the file
// This shows that values CAN be inputed in the main() function rather than void
int main(int argc, string argv[])
{
    // This is pretty basic and is not as function as the lines of codes below it.
    // if (argc == 2)
    // {
    //     printf("hello, %s\n", argv[1]);
    // } else
    // {
    //     printf("hello, world\n");
    // }

    // This solution plays on the idea that the user made a WRONG input rather than a correct input
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}