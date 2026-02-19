/*guilain 2014 6 jully*/
/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;
int blank_tile;

// prototypes 
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }
    else
    {
        // ensure valid dimensions
        d = atoi(argv[1]);
    }

    
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // TODO***************************************************
    int count=d*d-1;
    blank_tile = 95;

    for (int row=0; row<d; row++)
    {
        for(int col=0;col < d; col++)
        {
            board[row][col] = count;
            count--;
            board[d-1][d-1] = blank_tile;
        }
        
        if (d%2==0)
        {
            int tmp= board[d-1][d-2];
            board[d-1][d-2]=board[d-1][d-3];
            board[d-1][d-3]=tmp;
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO*****************************************************
    for (int row=0; row<d; row++)
    {
        for(int col=0;col < d; col++)
        {
            if(board[row][col]== blank_tile)
            {
                printf("%6c", blank_tile);
            }
            else
            {
                printf("%6d", board[row][col]);
            }
        }
        printf("\n\n");
    }
  
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO**********************************************************************
    //int tmp2;
    for (int row=0; row<d; row++)
    {
        for(int col=0;col < d; col++)
        {
            if (board[row][col] == tile)
            {
                if (board[row-1][col]== blank_tile)
                {
                    board[row-1][col]=tile;
                    
                    board[row][col]= blank_tile;
                    return true;
                }
                else if (board[row+1][col]== blank_tile)
                {
                    board[row+1][col]=tile;
                    board[row][col]= blank_tile;
                    return true;
                }
                 else if (board[row][col-1]== blank_tile)
                { 
                    board[row][col-1]=tile;
                    board[row][col]= blank_tile;
                    return true;
                }
                else if (board[row][col+1]== blank_tile)
                {
                    board[row][col+1]=tile;
                    board[row][col]= blank_tile;
                    return true;
                }
                else
                {
                    return false;
                }
            
            }
        }
    }
    return true;
 
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void) 
{
    // TODO ******************************************************************
   
    int tmp2=1;
    int tmp3=1;
    for(int row=0;row<d;row++)
    {
        for(int col=0;col<d;col++)
        {
            if (board[row][col]==tmp2 && tmp3==tmp2)
            {
                if (tmp2==d*d-1)
                {
                    return true;
                }
                tmp2++;
            }
         tmp3++;
      }
           
    }
    
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
