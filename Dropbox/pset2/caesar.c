#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc!=2)
        {
            printf("Invalid key, please retry\n");
            return 1;
        }
   
    int key = atoi(argv[1]);
    string txt = GetString(); 
    int p,c;
    
    
    for (int i = 0, a = strlen(txt);i<a;i++)
    {
        if(isalpha(txt[i]))
        {   
            if (islower(txt[i]))
            {
                p = txt[i]-97;
                c = (p+key)%26;
                printf("%c",c+97);
            }
            if (isupper(txt[i]))
            {
                p = txt[i]-65;
                c = (key+p)%26;
               
                printf("%c",c+65);
            }        
        }
        else
        {
                printf("%c",txt[i]);
        }
    }
        printf("\n");
}
    
