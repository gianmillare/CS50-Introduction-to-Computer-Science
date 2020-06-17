#include <stdio.h>
#include <cs50.h>
#include <math.h> // used for round function
#include <ctype.h> // used for isalpha function
#include <string.h> // This is used to obtain the length of a string

int count_letters(string x);
int count_words(string x);
int count_sentences(string x);
void cl_index(int x, int y, int z);

int main(void)
{
    // Get a string from the user
    string s = get_string("Text: ");

    int num_letters = count_letters(s);
    int num_words = count_words(s);
    int num_sentences = count_sentences(s);

    cl_index(num_letters, num_words, num_sentences);
}

// Function to count the number of letters
int count_letters(string x)
{
    int letters = 0;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if (isalpha(x[i]))
            letters++;
    }
    return letters;
}

// Function to count the number of words
int count_words(string x)
{
    int words = 0;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if ((i == 0 && x[i] != ' ') || (i != len - 1 && x[i] == ' ' && x[i+1] != ' '))
            words++;
    }
    return words;
}

// Function to count the number of sentences
int count_sentences(string x)
{
    int sentences = 0;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
            sentences++;
    }
    return sentences;
}

// Coleman-Liau index --> index = 0.0588 * L - 0.296 * S - 15.8
// L --> average number of letters per 100 words
// S --> average number of sentences per 100 words
void cl_index(int x, int y, int z)
{
    float L = (x / (float) y) * 100;
    float S = (z / (float) y) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
