// Implements a dictionary's functionality
#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

// Define the size of the Hash Table as 1000
#define HASHTABLE_SIZE 1000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// apply the hashtable to the struct node, this is where the words will be stored
node* hashtable[HASHTABLE_SIZE];

// create a variable that holds the number of words
unsigned int num_words = 0;

// create a boolean variable that shows if the dictionary was loaded
bool loaded_dict = false;

// Create the Hash Function; Hash Function credit: Deliberate Think --> ensures that the hash that is outputted is within hashtable range
unsigned int hash(const char* word)
{
    // Initialize hash as 0 first
    int hash = 0;
    // Create an integer value n
    int n;
    // loop through the word until you reach the end --> notated by '\0'
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }
        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
    }
    return hash;
}

// Function "Check" to check if the word is in the dictionary
bool check(const char* word)
{
    // create a variable that checks a word using the length of the word; makes a copy of the word
    char check_word[strlen(word)];
    // Use the strcpy function to compare the word passed into check_word and the word itself
    strcpy(check_word, word);

    // iterate through the word to make it lowercase
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    // create a variable index that passes the copy of the word (check_word) into the hash function
    int index = hash(check_word);

    // when the hash returns an index that exists in the node, compare the strings and return true if the strings match
    // if it returns "NULL" or if the strings do not match, then return false
    if (hashtable[index] != NULL)
    {
        for (node* node_pointer = hashtable[index]; node_pointer != NULL; node_pointer = node_pointer->next)
        {
            if (strcmp(node_pointer->word, check_word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}


// Function load that will load the dictionary
bool load(const char* dictionary)
{
    // read the file --> FILE* variable_name = fopen(filename, "r")
    FILE* infile = fopen(dictionary, "r");
    // if the read returns nothing or NULL, return false
    if (infile == NULL)
    {
        return false;
    }

    // Start all nodes inside the hashtable as NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // create char word[length + 1] as in the struct
    char word[LENGTH + 1];
    // declare a new pointer
    node* new_node_pointer;
    // use fscanf to search through the file until the end of the file
    while (fscanf(infile, "%s", word) != EOF)
    {
        num_words++;
        // Create a do-while loop to allocate memory for each node that is not NULL
        do
        {
            new_node_pointer = malloc(sizeof(node));
            // If the node I created returns a NULL value, I should free it to reduce memory used
            if (new_node_pointer == NULL)
            {
                free(new_node_pointer);
            }
        } while (new_node_pointer == NULL);

        // copy the word inside the new pointer into word
        strcpy(new_node_pointer->word, word);
        // get the index of the new word inside the hash function
        int index = hash(word);

        // Have the new pointer point to the index, even is it returns NULL
        new_node_pointer->next = hashtable[index];
        hashtable[index] = new_node_pointer;
    }
    // Close the files and return true
    fclose(infile);
    // update the boolean value of loading the dictionary
    loaded_dict = true;
    return true;
}

// Function to return the number of words in the dictionary (size)
unsigned int size(void)
{
    // if loaded_dict is false, return 0 because the dictionary didnt load any words
    if (!loaded_dict)
    {
        return 0;
    }
    // else return num_words which incremented during the fscanf
    else
    {
        return num_words;
    }
}


// Function to unload/free all nodes after the dictionary is loaded
bool unload(void)
{
    // if the dictionary wasnt loaded, return false
    if (!loaded_dict)
    {
        return false;
    }

    // iterate through the hashtable, as long as the value does not return NULL, I free node using a temp pointer
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            // first assign the pointer to the current node
            node* ptr = hashtable[i];
            // as long as the ptr does not equal NULL, continue to free up the memory
            while (ptr != NULL)
            {
                // have a temporary pointer equal the pointer
                node* tmp_pointer = ptr;
                ptr = ptr->next;
                free(tmp_pointer);
            }
        }
    }
    // return true after the ptr returns NULL, signaling the end of the nodes
    return true;
}