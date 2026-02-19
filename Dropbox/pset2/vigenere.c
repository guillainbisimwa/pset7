#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Invalid key, please retry\n");
        return 1;
    }
    string txt = argv[1];
    int b = strlen(txt);
         
    for (int aa=0;aa<b;aa++)
    {
        if (isalpha(txt[aa])==false)
        {
            printf("Please, put an alphabetical key\n");
            return 1;
        }
    }
     
    printf("taper le texte \n");
    string txt2 = GetString(); 

    int p,c,key,j=0,k=0;
 
    for (int i = 0, a = strlen(txt2);i<a;i++) 
    {  
      
        if (isalpha(txt2[i]))
        {
            j=k%b;
            if (islower(txt2[i]))
            { 
                key = tolower(txt[j]);
                key = key-97;
                p=(txt2[i])-97;
                c = (p+key)%26;
                
                printf("%c",c+97);
                
            }
            else if (isupper(txt2[i]))
            {
                key=toupper(txt[j]);
                key = key-65;
                p=(txt2[i]-65);
                c = (p+key)%26;
               
                printf("%c",c+65);
                
            }
            k++;
        }        
        
        else
        {    
            printf("%c",txt2[i]);   
        }
       
    }
    printf("\n");
}
    
