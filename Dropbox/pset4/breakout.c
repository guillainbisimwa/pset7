/*guilain 2014 6 jully*/
//
// breakout.c
//
// Computer Science 50
// Problem Set 4
// s
// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    //velocity
    double velo1 = drand48()*2;
    double velo2 = 1.0;
    
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        
      
        // move paddle
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL)
        {
            if(getEventType(event)==MOUSE_MOVED)
            {
                double x = getX(event)-getWidth(paddle)/2;
                double y = getY(paddle);
                setLocation(paddle, x, y);
             }
        }
        
        //move and bounce boule
        move(ball, velo1, velo2);
        if(getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velo1 = -velo1;
        }
        else if (getX(ball)<=0)
        {
            velo1 = -velo1;
        }
        else if (getY(ball)+getWidth(ball)>= getHeight(window))
        {
            setLocation(ball, getWidth(window)/2, getHeight(window)/2);
            waitForClick();            
            lives=lives-1;            
            if(lives==0)
            {                
                GLabel finalTxt = newGLabel("Game over");                
                setFont(finalTxt, "SansSerif-36");
                setLocation(finalTxt, getWidth(window)/4, getHeight(window)/2.5);
                add(window, finalTxt);
                break;
            }
        }
        else if (getY(ball)<=0)
        {       
            velo2 = -velo2;
        }
        pause(0);
        //GObject
        GObject detection = detectCollision(window, ball);
       
        if (detection == NULL || (strcmp(getType(detection),"GLabel")==0))
        {
            continue;       
        }
        
        else if(detection == paddle)
        {
            velo2 = -velo2;           
        }
        
        else 
        {
            velo2=-velo2;
            points=points+1;
            bricks=bricks-1;
            removeGWindow(window, detection);  
        }
        
          if (bricks ==0)
        {
            GLabel TxtWon = newGLabel("Congratulations");                
            setFont(TxtWon, "SansSerif-36");
            setColor(TxtWon, "orange");
            setLocation(TxtWon, getWidth(window)/9, getHeight(window)/2.5);
            add(window, TxtWon);
            break;
        } 
        
        // update score board (label)
        updateScoreboard(window, label, points);        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO************************************************************
    string color[5];
    color[0]="dark_gray";
    color[1]="green";
    color[2]="orange";
    color[3]="light_gray";
    color[4]="pink";
    
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            GRect brick = newGRect(7+(j*39),50+(i*25),35,15);
            setFilled(brick, true);
            setColor(brick, color[i]);
            add(window, brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO************************************************************************
    GOval boule =newGOval(getWidth(window)/2, getHeight(window)/2, 20, 20);
    setFilled(boule, true);
    setColor(boule, "red");
    add(window, boule);
    return boule;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO*********************************************************************
    GRect padd = newGRect(getWidth(window)/3, getHeight(window)-50, 93, 20);
    setFilled(padd, true);
    setColor(padd, "BLUE");
    add(window, padd);
    return padd;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO***************************************************************************
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
