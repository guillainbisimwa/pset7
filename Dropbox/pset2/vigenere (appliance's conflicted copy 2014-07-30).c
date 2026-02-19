#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
  /*bool bl;
  bl=isalpha(argv[1]);
  if (bl==false)
  {
     printf("saiaie errone\n");
     return 1;
  }
     if (bl==true)
     {*/
         string txt = argv[1];
         int b = strlen(txt);
         
     
     
     printf("taper le texte \n");
     string txt2 = GetString(); 

    int p,c,key,j;
 
  for (int i = 0, a = strlen(txt2);i<a;i++) 
  {  
      j=i%b;
      if (isalpha(txt2[i]))
      {
            if (islower(txt2[i]))
            { 
                
                key = txt[j]-97;
               p=(txt2[i])-97;
                c = (p+key)%26;
                printf("%c",c+97);
           }
            else if (isupper(txt2[i]))
            {
                key = txt[j]-65;
                p=(txt2[j]-65);
                c = (p+key)%26;
               
                printf("%c",c+65);
            }
            }        
        
        else
        {
                printf("%c",txt2[i]);
        }
       
    }
        printf("\n");
        
  // }
}
    
