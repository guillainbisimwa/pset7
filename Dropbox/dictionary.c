/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"


node hashtable[28][28][28];


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO *********************************************
    char buffer[LENGTH + 1];
    int i;
    for(i=0; word[i]!= '\0'; i++)
    {
        buffer[i]=tolower(word[i]);
    }
    buffer[i]= '\0';
    
    hashcont hashes = hash(buffer);
    
    if(hashtable[hashes.one][hashes.two][hashes.three].data == 0)
    {
        return false;
    }
    else if (hashtable[hashes.one][hashes.two][hashes.three].next == 0)
    {
        if (strcmp(hashtable[hashes.one][hashes.two][hashes.three].data, buffer) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        node* ptr = &hashtable[hashes.one][hashes.two][hashes.three];
        while (ptr != NULL)
        {
            if (strcmp(ptr->data, buffer) == 0)
            {     
                return true;
            }
            ptr = ptr->next;
        }
        
        
    }   
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO************************************************88
    char buffer[LENGTH + 1];   
    hashcont hashes;
    node* newnode;
    node* prenode;
    FILE* dict = fopen(dictionary, "r");
    int index;
    int c = 10;
    while(c!= EOF)
    {
        c = fgetc(dict);
        if(isalpha(c) || (c == '\'' && index > 0))
        {
            buffer[index] = c;
            index++;
        }
        else if (c == 10)  
        {
            buffer[index]= '\0';
            index = 0;
           
            hashes = hash(buffer);
            if(hashtable[hashes.one][hashes.two][hashes.three].data[0] == 0)
            {
                for(int i = 0; buffer[i] != 0;i++)
                {
                    hashtable[hashes.one][hashes.two][hashes.three].data[i]=buffer[i];
                    buffer[i]=0;
                }           
            }
            else if (hashtable[hashes.one][hashes.two][hashes.three].next == 0)
            {
                newnode = malloc(sizeof(node));
                for (int i=0;i<46;i++)
                {
                    newnode->data[i] = '\0';
                }
                newnode->next = NULL;
                for (int i=0;buffer[i] != 0;i++)
                {
                    newnode->data[i] = buffer[i];
                    buffer[i] = 0;
                }
                hashtable[hashes.one][hashes.two][hashes.three].next = newnode;   
            }
            else
            {
                newnode = malloc(sizeof(node));
                for (int i=0;i < 46;i++)
                {
                    newnode->data[i] = '\0';
                }
                newnode->next = NULL;
                prenode = &hashtable[hashes.one][hashes.two][hashes.three];
                for(int i = 0;buffer[i] != 0;i++)
                {
                    newnode->data[i]=buffer[i];
                    buffer[i]=0;
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
    // TODO **************************************************
    int counter = 0;
    for (int i = 0;i<28;i++)
    {
        for(int j = 0;j<28;j++)
        {
            for(int k = 0;k<28;k++)
            {
                if(hashtable[i][j][k].data[0] != 0)
                {
                    if (hashtable[i][j][k].next == 0)
                    {
                        counter++;
                    }
                    else if (hashtable[i][j][k].next !=0)
                    {
                        node* ptr = &hashtable[i][j][k];
                        while(ptr != NULL)
                        {
                            counter++;
                            ptr = ptr->next;
                        }
                    }
                }
            }
        }
    } 
    return counter;
    //return 0;
}
 // TODO ?????????????????????????????????????????????????????
/*bool freeNode(node* thisNode)
{
	for(int j=0;j<27;j++)
	{
		if(thisNode->children[j] != NULL)
		{
			freeNode(thisNode->children[j]);
		}
	}
	free(thisNode);
	return true;	
}
*/


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO *************************8
    for (int i = 0;i<28;i++)
    {
        for(int j = 0;j<28;j++)
        {
            for(int k = 0;k<28;k++)
            {
                if(hashtable[i][j][k].next != 0)
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
    //return false;
}


hashcont hash (const char* word)
{
    hashcont temp;
    if (word[1] == 0 || word [2] == 0 || word[1] == 39 || word[2] == 39)
    {
        if (word[1] == 0)
        {
            temp.one = word[0] - 'a' + 1;
            temp.two = 0;
            temp.three = 0;
            return temp;
        }
        else if(word[1] == 39)
        {
            temp.one = word[0] - 'a' + 1;
            temp.two = 0;
            if (word[2] != 0) temp.three = word[2] - 'a' + 1;
            return temp;
        }
        else
        {
            temp.one = word[0] - 'a' + 1;
            temp.two = word[1] - 'a' + 1;
            temp.three = 0;
            return temp;
        }
    }
    else
    {
        temp.one = word[0] - 'a' + 1;
        temp.two = word[1] - 'a' + 1;
        temp.three = word[2] - 'a' + 1;
        return temp;
    }
}

