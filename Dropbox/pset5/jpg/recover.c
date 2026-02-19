/*guilain 2014 6 jully*/
/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    // TODOS 
    int jpeg = 0;
    int a=0; 
    char title[8]="";
    BYTE table[512]={};
   
    FILE* card = fopen("card.raw","r");
    FILE* img;
    if(card == NULL)
    {
      printf("no memory card is found...\n");
      return 1;  
    }
    while(!feof(card))
    {         
        fread(&table,512,1,card);
        if((table[0] == 0xff ) && (table[1]== 0xd8 ) && (table[2]== 0xff ) && ((table[3]== 0xe0 ) || (table[3]== 0xe1)))
        {    
            if(a==1)
            {               
                fclose(img);
            }
            
            sprintf(title, "%.3d.jpg", jpeg++);
            img = fopen(title, "w");
            a=1;           
        }
        if(a==1)
        {
            fwrite(&table,512,1,img);
        }
        
    }            
        fclose(card);
        return 0;    
}
