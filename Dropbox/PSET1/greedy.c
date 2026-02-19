#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    printf("Greedy\n");
    printf("O hai, How much change is owed?\n");
    
    float nbr2;
    
    do
    {
        nbr2=GetFloat();
    }
    while(nbr2<=(-0.1));
    int nbr,cnt=0;
    float tmp;
    
    tmp = nbr2;
   
    nbr = round(tmp*100);
   
   
    while((nbr%25)!=nbr)
    {
        cnt=cnt+1;
        nbr=nbr-25;
    }
    
    while((nbr%10)!=nbr)
    {
        cnt=cnt+1;
        nbr=nbr-10;
    }
    
    while((nbr%5)!=nbr)
    {
        cnt=cnt+1;
        nbr=nbr-5;
    }
    
    while((nbr%1)!=nbr)
    {
        cnt=cnt+1;
        nbr=nbr-1;
    
    }
    printf("%d\n",cnt);
    
}
