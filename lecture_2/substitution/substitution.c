#include <stdio.h>
#include <cs50.h>
#include <string.h> //get length of a string
#include <ctype.h>

bool key_validity(string s);

int main(int argc, string argv[])
{
    // Check that two command line arguments were taken
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check that the key is valid --> function key_validity
    if (!key_validity(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string s = get_string("plaintext: ");

    // Create a new string array that takes in the difference between the plaintext and key
    string diff = argv[1];

    for (int i = 'A'; i <= 'Z'; i++)
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i;
    }

    printf("ciphertext: ");

    // Function to convert the plaintext to ciphertext
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            // Use the difference stored in the diff string array to convert the plaintext to its cipher
            s[i] = s[i] + diff[s[i] - (isupper(s[i]) ? 'A' : 'a')];
        }
        printf("%c", s[i]);
    }
    printf("\n");
}



// FUNCTION: key_validity --> check validity of inputted key
bool key_validity(string s)
{
    // Check that the key is exactly 26 letters long
    int len = strlen(s);
    if (len != 26)
    {
        return false;
    }

    // Create a frequency array with size 26 and all values starting at 0
    int freq[26] = { 0 };

    // Check that all characters in the string are letters
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }

        int index = toupper(s[i]) - 'A';
        // Check that each letter in the key appears only once --> counting each letter by comparing ASCII 'A'
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }
    return true;

}