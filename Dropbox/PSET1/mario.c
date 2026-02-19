#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Mario\n"); 
   
    int nbr,i=1,k=0,j=1;
  
    printf("How many staircases do you want?\n");
    do
    {
        nbr = GetInt();
    }
    while (nbr<=(-1)||nbr>=24);
 
    nbr=nbr+1;
    for(j=1;j<=nbr;j++)
    {
     
        for(i=j;i<=nbr-1;i++)
        {
            if(j!=1)
            {
                printf(" ");
            }
        }
        
        for(k=1;k<=j;k++)
        {
            if(j!=1)
            {
                printf("#");
            } 
        }
      
        printf("\n");
        }
  
}
