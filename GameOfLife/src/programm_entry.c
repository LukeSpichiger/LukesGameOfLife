#include "msleep.h"
#include <ncurses.h>

void PrintStartScreen(int duration_s){
    static int divisions = 43; //Loadingbar Size
    char loadingbar[43] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
                            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
                            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
                            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' '};
    char *charpos = &loadingbar[0];
    
    initscr();//initialize cursor mode
	raw();//disable inline buffering
	noecho();//echo swtiched off
	keypad(stdscr,FALSE);//function keys reading disabled
    
    //Print Welcome Screen
    for (int i = 0; i < divisions; i++) {
        printw("<==========[ Luke's Game Of Life ]==========>\n\n\n\n\n");
        printw("------------------Loading--------------------\n");
        printw("[");
        for (int j = 0; j < divisions; j++) {
            printw("%c", charpos[j]);
        }
        printw("]\n");
        charpos = &loadingbar[0];
        loadingbar[i] = '|';
        printw("---------------------------------------------\n");
        refresh();
        msleep(duration_s / divisions);
        clear();
    }
    msleep(1000);
    endwin();//end cursor mode
    return;
}