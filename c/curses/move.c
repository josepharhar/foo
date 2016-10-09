#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <stdio.h>

void sigintHandler(int dummy) {
    printf("captured sigint, exiting...\n");
    endwin();
    exit(0);
}

void initialize() {
    initscr(); // initializes screen
    cbreak(); // disables line buffering and keeps signals
    keypad(stdscr, TRUE); // captures function keys, etc.
    noecho(); // don't print to console when user types
}

int main(int argc, char **argv) { 

    initialize();

    signal(SIGINT, sigintHandler); // set SIGINT handler


    int ch;
    int y = 1234;
    int x = 1234;
    while (1) {
        ch = getch();
        y = getcury(stdscr);
        x = getcurx(stdscr);
        //printw("maxy: %d, maxx: %d\n", getmaxy(stdscr), getmaxx(stdscr));
        //printw("cury: %d, curx: %d\n", getcury(stdscr), getmaxx(stdscr));
        //refresh();

        if (ch == 'h') {
            // move left
            move(y, x - 1);
        } else if (ch == 'j') {
            // move down
            move(y + 1, x);
        } else if (ch == 'k') {
            // move up
            move(y - 1, x);
        } else if (ch == 'l') {
            // move right
            move(y, x + 1);
        }
        
        refresh();
    }

    endwin();

    return 0;
}
