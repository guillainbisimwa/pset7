/****************************************************************************
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include <stdint.h>
// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
typedef uint8_t HASH;

/**
* Returns true if word is in dictionary else false.
*/
bool check(const char* word);
/**
* Loads dictionary into memory. Returns true if successful else false.
*/
bool load(const char* dictionary);
/**
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void);
/**
* Unloads dictionary from memory. Returns true if successful else false.
*/
void affiche(void);

bool unload(void);
/**
* Hash function to be used when loading dictionary into hashtable
*/

#endif // DICTIONARY_H

