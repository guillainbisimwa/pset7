#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

int main(void)
{
    GWindow window = newGWindow(320, 240);
    //pause(5000);
    GOval cercle = newGOval(148, 0, 40, 40);
    setColor(cercle, "GREEN");
    setFilled(cercle, true);
    add(window, cercle);
    
    double velo = 2.0;
    
    while(true)
    {
        move(cercle, velo, 0);
        
        if(getX(cercle) + getWidth(cercle) >= getWidth(window))
        {
           velo= -velo;
        }
        else if(getX(cercle) <= 0)
        {
            velo=-velo;
        }
        pause(10);
        
        /*GEvent event = getNextEvent(MOUSE_EVENT);
        
        if(event != NULL)
        {
            if (getEventType(event)==MOUSE_CLICKED)
            {
                / *double x = getX(event) - getWidth(cercle)/2;
                double y = getY(event) - getWidth(cercle);
                setLocation(cercle, x, y);
                * /
                printf("%.0f, %.0f\n", getX(event), getY(event));
            }
        }
        */
   
    }
    
    
    //closeGWindow(window);
    //return 0;
}
