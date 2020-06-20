#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> // Used to convert types --> atoi
#include <string.h> // Used to get the length of a string
#include <ctype.h> // Used to check islower, isupper, and isalpha

bool key_validity(string s);
int convert_str_to_int(string s);

// Use argc, argv as your command-line argument
int main(int argc, string argv[])
{
    if (argc != 2 || !key_validity(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // convert the string key into an integer using atoi
    int key = convert_str_to_int(argv[1]);

    // get a plaintext from the user to encrypt
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}


// Function to check if the key is a valid number
bool key_validity(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to convert a string to int
int convert_str_to_int(string s)
{
    return atoi(s);
}


// Formula
// c = (p - A + k) % 26 + A --> where A is the ASCII number