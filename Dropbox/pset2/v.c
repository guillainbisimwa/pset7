#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

 string txt = GetString;
     printf("taper le texte \n");
     string txt2 = GetString(); 
     int b = strlen(txt2);
      
    int p,c,key,j;
    //b=b+1;
    //int i = 0;
       
  for (int i = 0, a = strlen(txt);i<a;i++) 
  {  

                j=i%b;
                key = txt2[j];
               p=(txt[i])-97;
                c = (p+key)%26;
                printf("%c",c+97);
               // printf("%d\n",i);
                //printf("%d\n",b);

    }
        printf("\n");
  
}
