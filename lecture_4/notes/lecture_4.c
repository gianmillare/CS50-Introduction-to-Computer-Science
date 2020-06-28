#include <stdio.h>
#include <cs50.h>
#include <ctype.h> // used to manipulate the font
#include <string.h> // get string length
#include <stdlib.h> // used for malloc


// Part 1: changing the 'training wheels' to 'conventional methods'
// --> Training Wheels version of strings (using cs50 library)
// int main(void)
// {
//     string s = "EMMA";
//     printf("%s\n", s);
// }

// // Conventional Method of Strings --> provides the same output as training wheels method
// int main(void)
// {
//     char *s = "EMMA";
//     printf("%s\n", s);
//     printf("%p\n", s); // --> returns the hexidecimal value of "E" --> 0x400704
//     printf("%p\n", &s[0]); // --> returns the same as above, hexidecimal value of "E" --> 0x400704
//     printf("%p\n", &s[1]); // --> this and the below will return the hexidecimal value of all "EMMA" --> 0x400705
//     printf("%p\n", &s[2]); // --> 0x400706
//     printf("%p\n", &s[3]); // --> 0x400707
//     printf("%c\n", *s); // --> this will got to the value that matches the hexidecimal value, or go to the go to --> "E"
//     printf("%c\n", *(s+1)); // --> this and the below will return the element that matches the hexidecimal value --> "M"
//     printf("%c\n", *(s+2)); // --> "M"
//     printf("%c\n", *(s+3)); // --> "A"
// }





// // Part 2: Compare
// // Example 1: This will work as integers even when stored in different variables
// int main(void)
// {
//     int i = get_int("i: ");
//     int j = get_int("j: ");

//     if (i == j)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }

// // Example 2: This will NOT work because both strings are stored in different locations. --> Emma != Emma
// // string i is located at 0x123 and string j is located at 0x456
// int main(void)
// {
//     string i = get_string("i: "); // --> equivalent of char *i
//     string j = get_string("j: "); // --> equivalent of char *j

//     if (i == j)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }


// // Example 3: Even when passed the same value, strings are not equivalent because they are stored in different memory
// int main(void)
// {
//     char *i = get_string("i: ");
//     char *j = get_string("j: ");

//     printf("%p\n", i); // --> input:Emma --> This returns a location of 0xb28670
//     printf("%p\n", j); // --> input:Emma --> This returns a location of 0xb286b0
// }






// // Part 3: Copy
// // Example 1: Even if we set a value of one variable to equal the value of another variable, if we alter the second variable
// // Both variables are still changed
// int main(void)
// {
//     string s = get_string("s: "); // equivalent of char *s

//     string t = s; // equivalent of char *t

//     // we change the variable t to uppercase.
//     t[0] = toupper(t[0]);

//     printf("%s\n", s);
//     printf("%s\n", t);
//     // both variables are uppercased. Including string s even when not specifically told to.
//     // This is because both "pointers" are pointing to the same location, string s with address 0x123
//     // so when we alter string t, the location is altered, which both s and t share
// }


// // Example 2: How to work around altering a variable that is pointing to the same address
// // Using the function "malloc()" --> Emma\0 --> 5 bytes needed --> strlen(s) + 1
// int main(void)
// {
//     char *s = get_string("s: ");

//     char *t = malloc(strlen(s) + 1);

//     for (int i = 0, n = strlen(s); i < n + 1; i++) // we add +1 to i < n because we need to include the null operator at the end
//     {
//         t[i] = s[i];
//     }

//     t[0] = toupper(t[0]);

//     printf("%s\n", s);
//     printf("%s\n", t);
//     // string s is still lowercase as we change string t to uppercase.
// }






// Part 4: Freeing Memory and Debugging
// via valgrind ./file --> help50 valgrind ./file --> use free(t)
// int main(void)
// {
//     char *s = get_string("s: ");
//     char *t = malloc(strlen(s) + 1); // --> when running valgrind, this is the area that is accused of leaking memory

//     for (int i = 0, n = strlen(s); i < n + 1; i++)
//     {
//         t[i] = s[i];
//     }

//     t[0] = toupper(t[0]);

//     printf("%s\n", s);
//     printf("%s\n", t);

//     free(t); // --> this is where we can remedy the memory leak, where t is the variable that is leaking memory
// }





// // Part 5: Swap & Empty Variables/Temp
// // Sometimes we will need to switch variables WITHOUT overwriting the value already stored in a variable
// // We can do this by using a temprary variable
// void swap(int a, int b)
// {
//     int temporary_variable = a; // store the value of a in a temp
//     a = b; // change a to b
//     b = temporary_variable; // change b to temp
// }

// // However, this does not work when calling in a main function because it swaps a and b, copies of whatever variables you are
// // swapping in the main function --> references at lecture_4.txt

// // SOLUTION: We can resolve this by using Pointers --> Address (* and &)
// void swap(int *a, int *b);

// int main(void)
// {
//     int x = 1;
//     int y = 2;

//     printf("x is %i, y is %i\n", x, y);
//     swap(&x, &y);
//     printf("x is %i, y is %i\n", x, y);
// }

// void swap(int *a, int *b)
// {
//     int temporary_variable = *a; // store the value of a in a temp
//     *a = *b; // change a to b
//     *b = temporary_variable; // change b to temp
// }





// // Part 6: scanf --> Another way of getting an integer from the user --> replaces "get_int", "get_string"
// // Another way of taking off the training wheels
// // int main(void)
// {
//     int x;
//     printf("x: ");
//     scanf("%i", &x);
//     printf("x: %i\n", x);
// }
// int main(void)
// {
//     char s[5];
//     printf("s: ");
//     scanf("%s", s);
//     printf("s: %s\n", s);
// }





// Part 7: Files and Opening Files
// Writing/updating the csv file via this program/code --> will write in any inputs into a new file called "Phonebook"
// int main(void)
// {
//     // Open File
//     FILE *file = fopen("phonebook.csv", "a"); // r = read, w = write, a = append

//     // get strings from user
//     char *name = get_string("Name: ");
//     char *number = get_string("Number: ");

//     // Print / write strings of file
//     fprintf(file, "%s, %s\n", name, number);

//     // close the file
//     fclose(file);
// }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    File *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        return 1;
    }

    // IMPORTANT: Reads the first 3 bytes, 24 bits from the file
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    // Check the bytes are hexidecimal --> 0xff 0xd8 0xff --> this is how you check if a file is a jpeg/image
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }
    else
    {
        printf("Not\n");
    }
}