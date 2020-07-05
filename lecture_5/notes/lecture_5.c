#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> // used for malloc

// // Part 1 - Review of memory - Debugging
// int main(void)
// {
//     int *x;
//     int *y;

//     x = malloc(sizeof(int));

//     // *x = 42;
//     // *y = 13 // this is the bug

//     // Debug solution 1
//     // y = malloc(sizeof(int));

//     *x = 42;
//     // Debug solution 2 --> but this overrides the data inside memory allocated in x
//     y = x;
//     *y = 13;
// }









// // Part 2 - how to add another box of memory into an array after declaring the arrays size
// // You can create a new array and move the values in the old array to the new array --> not efficient

// int main(void)
// {
//     // // Creating a list to show how to add another block of memory to add a value to a list
//     // int list[3];

//     // list[0] = 1;
//     // list[1] = 2;
//     // list[2] = 3;

//     // for (int i = 0; i < 3; i++)
//     // {
//     //     printf("%i\n", list[i]);
//     // }

//     // Solution --> adding another block to an array for room for another value via malloc()
//     int *list = malloc(3 * sizeof(int)); // this assigns a variable list to the amount of memories needed for each integer added to "list"
//     // best practice to check if you receive null when allocating memory
//     if (list == NULL)
//     {
//         return 1;
//     }

//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;

//     //  create a new value called temp to add a new block of memory into the array --> 3 -> 4
//     int *tmp = malloc(4 * sizeof(int));
//     if (tmp == NULL)
//     {
//         return 1;
//     }

//     // copy integers from old array to the new array
//     for (int i = 0; i < 3; i++)
//     {
//         tmp[i] = list[i];
//     }
//     // now store the new value into the added box of memory
//     tmp[3] = 4;

//     free(list); // free up the memory used above

//     list = tmp;

//     // print out all the values of the array
//     for (int i = 0; i < 4; i++)
//     {
//         printf("%i\n", list[i]);
//     }
// }










// // Part 3: Realloc
// int main(void)
// {
//     int *list = malloc(3 * sizeof(int));
//     if (list == NULL)
//     {
//         return 1;
//     }

//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;

//     // You can reallocate memory to make code cleaner and faster than Part 2 Solution
//     int *tmp = realloc(list, 4 * sizeof(int)); // --> resizes the memory used in the array
//     if (tmp == NULL)
//     {
//         return 1;
//     }

//     // assign list to equal tmp
//     list = tmp;

//     tmp[3] = 4;

//     for (int i = 0; i < 4; i++)
//     {
//         printf("%i\n", list[i]);
//     }

//     free(list;)
// }









// Part 4: Data Structures --> Linked Lists
// LINKED LISTS --> similar to an array, but uses an arbitrary 'NULL' space to 'point' to another value
// --> This means that even if the memory allocated for the array values were located in different places
// --> the arrays would still function correctlt; they are linked by pointers
// --> value1, pointer to value2, value2, pointer to value3, value3, Null

// typedef struct node
// {
//     int number;
//     struct node *next;
// }
// node;

// if the linked list is empty or you dont know what to put into it
// --> node *list = NULL;
// --> node *n = malloc(sizeof(node)); --> temporary variable

// if you want to add in a value into a linked list, you must allocate memory for both the value and the pointer
// a value/pointer pair is called a "NODE"
// --> n->number = # --> this is how you assign a value to the node's property
// --> n-> next = NULL;
// Best way to write this node allocation
// if (n != NULL)
// {
//     n->number = 2;
//     n->next = NULL;
// }
//  list = n;

// // To update arrows and link nodes together
// // Assign a temporary value to the linked list
// node *tmp = list;
// // while the value inside the tmp list i NOT NULL, keep moving down each node
// while (tmp->next != NULL)
// {
//     tmp = tmp->next;
// }
// tmp->next = n;
// // once the pointer hits a NULL value

// // *****IMPLEMENTING A LINKED LIST USING NODE NOTATION*****
// typedef struct node
// {
//     int number;
//     struct node *next;
// }
// node;

// int main(void)
// {
//     // List of size 0 (NULL) --> we do not know how many values are in the list, or we know that it is empty
//     node *list = NULL;

//     // Add a value to the linked list
//     node *n = malloc(sizeof(node)); // --> initiallize the first node by allocating memory to contain the node
//     if (n == NULL) // --> check that the value we are inserting into the linked list is not NULL
//     {
//         return 1;
//     }
//     n->number = 1; // --> insert the value into node n
//     n->next = NULL; // --> insert the pointer value of node n as NULL
//     list = n; // --> assign the linked list to equal the new node value to point at the new node



//     // add another value into the list when the linked list already has a value (1)
//     n = malloc(sizeof(node)); // --> call malloc again to create a new node "n" which is empty
//     if (n == NULL) // --> check that the value n is not NULL
//     {
//         return 1;
//     }
//     n->number = 2; // --> assign the value 2 to the new node n
//     n->next = NULL; // --> assign the value NULL to the new node n pointer value
//     list->next = n; // --> go through the previous linked list to find value "NULL" which is now at the end of node 2
//     // the "->" between list and next allows the pointer to continue past node 1



//     // add another value into the list when the linked list already has a value (2)
//     n = malloc(sizeof(node)); // --> call malloc afain to create a new node "n" which is empty
//     if (n == NULL) // --> check that the value n i not NULL
//     {
//         return 1;
//     }
//     n->number = 3; // --> assign the value 3 to the new node
//     n->next = NULL; // --> assign the value NULL to the new node's pointer
//     list->next->next = n; // --> go trhough the linked list to find value NULL at the end of node 3
//     // --> the "->next->" in between list and the final next allows the pointer to go past node 1 and 2


//     // Print the linked list --> iterating over a linked list
//     for (node *tmp = list; tmp != NULL; tmp = tmp->next)
//     {
//         printf("%i\n", tmp->number);
//     }

//     // Free the list of floating memory
//     while (list != NULL)
//     {
//         node *tmp = list->next;
//         free(list);
//         list = tmp;
//     }
// }








// // Part 5: Data Structures --> Binary Search Trees
// // looks like the below
// typedef struct node
// {
//     int number;
//     struct node *left;
//     struct node *right;
// }
// node;

// Recursive because --> everything to the left of a node root is smaller and everything to the right of the root is greater


// // *****BASIC BINARY SEARCH TREE*****
// bool search(node *tree) // pass in the address of the top node, also called the "root"
// {
//     // Base Case
//     if (tree == NULL)
//     {
//         return false;
//     }
//     // if the number we're looking for (50) is less than the root, go left, else go right
//     else if (50 < tree->number)
//     {
//         return search(tree->left);
//     }
//     else if (50 > tree->number)
//     {
//         return search(tree->right);
//     }
//     else
//     {
//         return true;
//     }
// }







// // Part 6: Data Structures --> Hash Table
// Combination of an array and a linked list
// --> for example: nametags. Instead of a gigantic pile, sorted each name in "buckets" based on first letter of your name
// Hash Tables focus on creating an array of linked lists by taking the CHARACTERS of a value
// --> Hash Tables are inherently vertically as an array and horizontally a linked list
// Hash Function --> algorithm that takes an input and stores the value based on some sort of characteristic
// Example:
    // --> Search for names that start with "H"
    // --> Result ==> (1) Hermione, Harry, Hagrid
    // --> Search for names that start with "Ha" or "He"
    // --> Result ==> (1) Hermione, (2) Harry, Hagrid
    // --> Search for names that start with "Her", "Har", or "Hag"
    // --> Result ==> (1) Hermione, (2) Harry, (3) Hagrid








// // Part 7: Data Structures --> Tries
// if you want to store a value, look through all characters in the value
// stores 1 node/array for each character in a value ("Hagrid")
// Now lets say we want to look for Harry and Hermione
    // --> We can REUSE NODES, so each node is shared for each value
    // --> "H" is shared between all three
    // --> "Ha" is shared between Hagrid and Harry
// --> Tries provide a Big 0 notation of O(1) because the search is fixed
// --> However, this ALSO takes up the most memory









// // Part 8: Data Structures --> Abstract Data Structures
// Queues --> data structure that is first in and first out (FIFO)
// Enqueue --> get in line (pushing)
// Dequeue --> get out of line (popping)
// Stacks --> usually implements a last in first out (LIFO)
    //  --> emails. most recent emails end up at the top
// Dictionary --> abstraction of an array that contains keys and values











// Part 9: Shorts

// *****DATA STRUCTURES OVERVIEW*****
Data Scructure 1 ==> Arrays
    - insertion --> bad
    - deletion --> bad
    - lookup --> good
    - relatively easy to sort
    - relatively small
    - stuck with a fixed size, no flexibility (according to C language)

Data Structure 2 ==> Linked List
    - insertion --> easy
    - deletion --> easy
    - lookup --> difficult, bad (linear search)
    - sorting --> difficult (have to compromise other nodes)
    - relatively small

Data Structure 3 ==> Hash Tables
    - insertion --> two step process
    - deletion --> easy once found the element
    - Lookup --> better than linked lists, there is a constant
    - sorting --> not ideal
    - can run the gamut of size

Data Structure 4 ==> Tries
    - insertions --> complex, but gets easier
    - deletion --> easy
    - lookup --> fast, but not as fast as arrays
    - already sorted
    - takes up a lot of memory/space




// *****SINGLY-LINKED LISTS*****
- Recall that "structs" give us containers for holding different data types in one area
- remember that Arrays are usually inflexible, difficult add in more values and allocate memory
- Singly-Linked List allows us to manipulate an array easily:
    - Comprised of nodes --> each node houses (1) data, (2) pointer to another node (if one exists)
    - typedef struct sllist // --> remember that this can be any name as long as the same name is called inside the struct
        {
            VALUE val;
            struct sllist* next;
        }
        sllnode; // --> remember that this is the name you call

    - ****Linked List Operations Guidelines*****
        - Create a linked list
        - search through the linked list
        - insert a new node into the linked list
        - delete a node
        - delete the entire linked list

        1) Create a linked list --> sllnode* create(VALUE val); sllnode* create(6);
            - malloc space for the node
            - initilaize the value field
            - initialize the next node (usualize NULL)
            - return a pointer to the newly create node

        2) Search through a linked list to find an element --> bool find(sllnode* head, VALUE val);
            - create a temporary pointer to the list's head, and will go through all the nodes of a linked list
            - if the current nodes value field is what we need, return success
            - if not, set the pointer to the next node in the list
            - if it hits the end, return failure.
            - Example --> bool exists = find(list, 6)

        3) Insert a new node into the linked list --> sllnode* insert(sllnode* head, VALUE val);
            - malloc space for a new node
            - populate the node (put in values), insert the node at the beginning of the linked list
                - because pointers begin at the root node, and we can move pointers throughout the operations
            - return a pointer to the new haed fo the linked list
                - first the new elements pointer points to the head of the linked list
                - THEN you can have the "list" pointer to point at the value of the new node

        4) Delete an entire list --> void destrpy(sllnode* head);
            - if you reached a null pointer
            - delete the rest of the list
            - free the current node
            - Recursion will help
                - Delete the rest of the list until you find a null pointer
                - the deletion of each node will be placed on hold until a null value is found
                - in other words, it will delete from the end of the linked list


// *****HASH TABLES*****
- Combine the random access ability of an array with the dynamism of a linked list
- First part --> Hash Function returns a nonegative integer value called a hash code
    - Hash Function Guidelines
        - USes only and all data being hashed
        - must be deterministic, same data passed should provide same data outputed
        - uniformly distributed
        - MOST OF THE TIME, a hash function is already implemented, and you wont be making your own hash function
- Second part --> Array capapble of sorting data of the type we wish to place into the data structure
- A collision occurs when two pieces of data , when run through the hash function, yields the same hash code
    - Usually, we want to keep both pieces of data in the hash table, not overwrite the previous one
    - LINEAR PROBING: resolving collisions
        --> place the data in the next consecutive element in the array
        --> this will eventually wrap around to the beginning of the array and place the value at the next available array slot
    - CHAINING: Solution to when all elements of an array are taken by a table
        - each element of an array are pointers to a linked list
        - This effectively solves the idea of collisions and running out of elements in an array --> eliminating clustering
- HASH TABLE DEFINITION SYNTAX --> a hash table is an array of pointers pointing to array of nodes (Linked List)





// *****TRIES*****
- Key is guaranteed to be unique, and the output is a boolean value of whether a piece of information exists in a structure
- Tries combine structures and pointers together to store data
    - the data is viewed as a roadmap to find whether data exists or not
    - in a Trie, the paths from a ventral root node to a leaf node, and each root and lead can go to 10 different pointers (0-9)
    - To INSERT an element into the Trie, simply build the correct path from the root to the leaf
        --> Example: an array and 10 pointers
        - typedef struct _trie
            {
                char_university[20];
                struct _trie* paths[10];
            }
            trie;
    - Begin with a root node, which is usually globally declared
    - The root would have 10 pointers underneath it
    - if a key is not found, you need to allocate the memory and build a node
        - Example: Going down every value in "1636" to find "Harvard"
            - Start at the root, create a new node by going down the "1" pointer
            - create a new node by branching off the previous step and going down the "6" pointer
            - again for 3 pointer
            - again for 6 pointer
            - at the end of pointer/branch 1, and 6, and 3, and 6 --> new node below 6 will have "Harvard"
        - Now that we have nodes 1, 6, 3, 6 --> can go down these roots but this time we can REUSE previous nodes
        - Example: "SHARING" previous nodes to find "Yale" with key "1701" and "Dartmouth" with key "1769"
    - To SEARCH for an element, use sucessive digits to navigate from the root
        --> If you can make it to the end of the Trie without hitting a "NULL", the search will return true
    - Using the tree from above, if we searched for "Harvard" after inputting "1636" --> return true
        --> by going down key 1 -> 6 -> 3-> 6
    - But if we looked for "Online University" with key "2020"
        --> unable to locate because root node with pointer "2" was not created in this Trie --> return false.