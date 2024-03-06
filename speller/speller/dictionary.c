// Implements a dictionary's functionality
// Including Necessary Libraries
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

#include "dictionary.h"

// Defining node for hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Total number of buckets in hash table
const unsigned int N = 26;

// Initializing Variable Integer count_words for keeping count of total words
int count_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Taking Integer hash_index for storing Hash()'s index value
    int hash_index;

    // Assigning the index value from hash function to hash_index
    // Passing address of first letter of word string to hash function
    hash_index = hash(&word[0]);

    // Taking Temporary tmp pointer and assigning it the Value of Table[index]
    // Run the loop as long as tmp does not equal NULL
    // Assign next->tmp to tmp after the loop ends
    for (node *tmp = table[hash_index]; tmp != NULL; tmp = tmp->next){

        // If word string stored in tmp->word matches with word passed to the check function; Return true
        if (strcasecmp(tmp->word, word) == 0){
            return true;
        }
    }

    // If not found in Dictionary, return false
    return false;
}

// Finds index value for Hash table according to first alphabet of the word passed in the hash()
unsigned int hash(const char *word)
{
    int index;

    // If word lies between A and Z or a and z, run the loop
    if ((*word >= 'A' && *word <= 'Z') || (*word >= 'a' && *word <= 'z')){

        // Run the loop 26 times for each bucket of Hash table
        for (int i = 0; i < 26; i++){

            // If word's first alphabet matches with ASCII value of A or a plus i value, that means the first letter is equal to that value of ASCII and then we assign index to that i value, which will be taken as index value to store the word in Hash table, and index will be returned from this function
            if (*word == 'A' + i || *word == 'a' + i){
                index = i;
            }
        }
        return index;
    }

    // If not found, return error 1;
    else {
        return 1;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Taking word string of LENGTH = 45, plus 1
    char word[LENGTH + 1];

    // Taking variable for storing index
    int index_check;

    // Declaring FILE *dict
    FILE *dict;

    // Opening dictionary as read and assigning to file pointer dict
    dict = fopen(dictionary, "r");

    // If dict is empty in case of some issue, return false;
    if (dict == NULL){
        return false;
    }

    // As long as the fscanf doesnt return End Of File, keep the while loop running
    // Read Dictionary strings into word variable
    while (fscanf(dict, "%s", word) != EOF){

        // Declaring new node n
        node *n = malloc(sizeof(node));

        // If n is equal to NULL, close dictionary and return false
        if (n == NULL){
            fclose(dict);
            return false;
        }

        // Copy string from word to n->word
        strcpy(n->word, word);

        // Call hash() and pass address of first alphabet of word string
        index_check = hash(&word[0]);

        // Assigning the table[index] to n->next
        n->next = table[index_check];

        // Assigning table[index] the new node of n
        table[index_check] = n;

        // Increment words as loop iterates
        count_words += 1;

    }

    // If the code runs as intended, close dict and return true
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Returns count_words
    return count_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < 26; i++){

        // Taking new node of point and assigning address of table[i]
        node *point = table[i];

        // First assigning tmp pointer node to table[i], then assigning the point node to point->next and freeing tmp
        // As the loop iterates, tmp is given address of point again
        for (node *tmp = table[i]; tmp != NULL; tmp = point){
            point = point->next;
            free(tmp);
        }
    }

    // Returning true if all memory is freed
    return true;
}
