/*guilain 2014 6 jully*/
/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: Only 2 or 3 command-line arguments are allowed 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // TODO: Convert the initial part of the second argument to an integer
    int n = atoi(argv[1]);

    // TODO: convert the third comment-line argument to a positive integer and/or
    //set it as the seed for n of pseudo-random  integers  to be returned by rand().
    
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // TODO: Return n pseudo-random integer between 0 and 65536 (LIMIT) inclusive taken on srand
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
