#include <stdlib.h>
#include <curses.h>
#include <signal.h>

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

int main() {
    initialize();

    signal(SIGINT, sigintHandler); // set SIGINT handler

    printw("Type any character to see it in bold\n");

    int ch;
    while (1) {
        ch = getch();
        printw("The pressed key is: ");
        attron(A_BOLD);
        printw("%c\n", ch);
        attroff(A_BOLD);
    }

    endwin();
    
    return 0;
}
