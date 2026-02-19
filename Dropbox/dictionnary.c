
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
﻿#include <ctype.h>

#include "dictionary.h"

int worldsload=0;

typedef struct node
{
	bool is_world;
	stuct node* children[27];
}
node;

node* root;

/*retourner vrai si le mot est dans le dictionnaire et faux dans le cas contraire*/

bool check(const char* word)
{
	int i=0;
	while(word[i]!='\0')
	{
		char input=word[i];
		if (word[i]=='\'')
		{
			input ='z'+1;
		}
		int newnum=tolower(input)-'a';
		
		if(current->children[newnume] != NULL)
		{
			current = current->children[newnume];
			i++;
		}
		else
		{
			return false;
		}
	}
	if (current->is_word == true)
	{
		return true;
	}
	return false;
}


/*Chargement du dictionnaire dans la memoire. retourner vrai si fait et faut dans l'autre cas*/

bool load(const char* dictionary)
{
	FILE* dict = fopen(dictionary, "r");
	if (dict == NULL)
	{
		return false;
	}
	root = malloc(sizeof(node));
	int c = 0;
	node* current = NULL;

	while(fgetc(dict) != EOF)
	{
		fseek(dict, -1,SEEK_CUR);
		//curseur sur le root
		current=root;

		for(c = fgetc(dict);c != '\n';fgetc(dict))
		{
			//recherche d'appostrophe
			if (c == '\'')
			{
				//metre ca au plus grand lettre past 1
				c= 'z'+1;
			}
			//cherche si le caractere exist dans l'arbre
			
			if (current->children[c-'a']== NULL)
			{
				//si le caractere n'existe pas, malloc un new node
				current->children[c-'a']=malloc(sizeof(node));

				//aller au new node
			}	current = current->children[c-'a'];
			else 
			{
				//aller au new node desormais present
				current = current->children[c-'a'];
			}
		}
		current->is_word = true;
		wordsloaded++;
	}
	fclose(dict);
	return true;	
}


/*retourner le nombre de mots ds le dico si il est ouvert ou 0 si no ouvert*/
unsigned int size(void)
{
	return wordsloaded;
}





/* liberer le dico de la memoir retourner vrai s'il est possible et faux ds d'autre cas*/
bool freeNode(node* thisNode)
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


bool unload(void)
{
	return freeNode(root);
}
























































