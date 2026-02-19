/*guilain 2014 3 october*/
/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// declare hastable ( three first letter)
node hashtable[28][28][28];
/**
*  true if word is in the dictionary else false.
*/
bool check(const char* word)
{
    char buffer[LENGTH + 1];
//  lowercase letters, and copy to char buffer
    int i;
    for (i = 0; word[i] != '\0'; i++)
    {
        buffer[i] = tolower(word[i]);
    }
    buffer[i] = '\0';
// declare hash container
    hashcont hashes = hash(buffer);
// check if the list contains any word with the first three chars
// returns false if not
    if (hashtable[hashes.un][hashes.deux][hashes.troi].data == 0)
    {
        return false;
    }
// check if the hashtable doesn't contain linked list
    else if (hashtable[hashes.un][hashes.deux][hashes.troi].next == 0)
    {
// Checks for the word, returns true/false
        if (strcmp(hashtable[hashes.un][hashes.deux][hashes.troi].data, buffer) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
// the hashtable contains a linked list, check that for the word
    else
    {
        node* ptr = &hashtable[hashes.un][hashes.deux][hashes.troi];
        while (ptr != NULL)
        {
            if(strcmp(ptr->data, buffer) == 0)
            {
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}
/**
* Loads dictionary into memory. Returns true if successful else false.
*/
bool load(const char* dictionary)
{
// declare buffer of size LENGTH + 1
    char buffer[LENGTH + 1];
    hashcont hashes;
    node* newnode;
    node* prenode;
    // Open dictionary 
    FILE* dict = fopen(dictionary, "r");
    int test = 0;
    int comp = 10;
    while (comp != EOF)
    {
        comp = fgetc(dict);
        // allow only alphabetical characters and apostrophes
        if (isalpha(comp) || (comp == '\'' && test > 0))
        {
            // append character to word
            buffer[test] = comp;
            test++;
        }
        else if (comp == 10)
        {    
            buffer[test] = '\0';
            test = 0;
            hashes = hash(buffer);
            if (hashtable[hashes.un][hashes.deux][hashes.troi].data[0] == 0)
            {
                // store the word in the appropiate location in hashtable, and delete buffer meanwhile
                for (int i = 0; buffer[i] != 0; i++)
                {
                    hashtable[hashes.un][hashes.deux][hashes.troi].data[i] = buffer[i];
                    buffer[i] = 0;
                }
            }
            // store in hashtable if spot is occupied, but doesn't contain linked list
            else if (hashtable[hashes.un][hashes.deux][hashes.troi].next == 0)
            {
                // new node
                newnode = malloc(sizeof(node));
                for (int i = 0; i < 46; i++)
                {
                    newnode->data[i] = '\0';
                }
                newnode->next = NULL;
                // store in node->data
                for (int i = 0; buffer[i] != 0; i++)
                {
                    newnode->data[i] = buffer[i];
                    buffer[i] = 0;
                }
                // link the node in the list
                hashtable[hashes.un][hashes.deux][hashes.troi].next = newnode;
            }
            else
            {
                // allocate new node
                newnode = malloc(sizeof(node));
                for (int i = 0; i < 46; i++)
                {
                    newnode->data[i] = '\0';
                }
                newnode->next = NULL;
                // allocate previous node, with address of hashtable
                prenode = &hashtable[hashes.un][hashes.deux][hashes.troi];
                for (int i = 0; buffer[i] != 0; i++)
                {
                    newnode->data[i] = buffer[i];
                    buffer[i] = 0;
                }
                    
                while (prenode->next != 0)
                {
                    prenode = prenode->next;
                }
            
                prenode->next = newnode;
            }
        }
    }
    fclose(dict);
    return true;
}
/**
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void)
{
    int counte = 0;
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            for (int k = 0; k < 28; k++)
            {                
                if (hashtable[i][j][k].data[0] != 0)
                {
           
                    if (hashtable[i][j][k].next == 0)
                    {
                        counte++;
                    }
                
                    else if (hashtable[i][j][k].next != 0)
                    {
                        node* ptr = &hashtable[i][j][k];
                        while (ptr != NULL)
                        {
                            counte++;
                            ptr = ptr->next;
                        }
                    }
                }
            }
        }
    }
    
    return counte;
}

/**
* Unloads dictionary from memory. Returns true if successful else false.
*/
bool unload(void)
{
        
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            for (int k = 0; k < 28; k++)
            {          
                if (hashtable[i][j][k].next != 0)
                {       
                    node* cursor = hashtable[i][j][k].next;
            
                    while (cursor != NULL)
                    {
        
                        node* temp = cursor;        
                        cursor = cursor->next;
                        free(temp);
                    }
                }
            }
        }
    }
    return true;
}


/**
* Hash function to be used when loading dictionary into hashtable
*/
hashcont hash(const char* word)
{
// temporary hash container
    hashcont temp;
// if letter contains apostrophe or is less than 3 chars
    if (word[1] == 0 || word[2] == 0 || word[1] == 39 || word[2] == 39)
    {
        if (word[1] == 0)
        {
            temp.un = word[0] - 'a' + 1;
            temp.deux = 0;
            temp.troi = 0;
            return temp;
        }
        else if (word[1] == 39)
        {
            temp.un = word[0] - 'a' + 1;
            temp.deux = 0;
            if (word[2] != 0) temp.troi = word[2] - 'a' + 1;
            return temp;
        }
        else
        {
            temp.un = word[0] - 'a' + 1;
            temp.deux = word[1] - 'a' + 1;
            temp.troi = 0;
            return temp;
        }
    }       
    else
    {
        temp.un = word[0] - 'a' + 1;
        temp.deux = word[1] - 'a' + 1;
        temp.troi = word[2] - 'a' + 1;
        return temp;	
    }
}

//finish
