#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main ()
{
    printf("taper la lettre\n");
    char* t = GetString();
    printf("taper la lettre\n");
    char* s = GetString();
    
    if(t != NULL && s != NULL)
    {
    
        if(strcmp(t,s)== 0)
        {
            printf("\nbravo\n");
        }
        else
        {
            printf("\nechec \n");
        }
    }
} 
