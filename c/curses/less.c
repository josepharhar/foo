#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>

#define LINE_LENGTH 4096

FILE* inFile = NULL;

void endProgram() {
    endwin();
    if (inFile) {
        fclose(inFile);
    }
    exit(0);
}

void sigintHandler(int dummy) {
    printf("captured sigint, exiting...\n");
    endProgram();
}

void initialize() {
    initscr(); // initializes screen
    cbreak(); // disables line buffering and keeps signals
    keypad(stdscr, TRUE); // captures function keys, etc.
    noecho(); // don't print to console when user types
}

// update stdscr with info from file based on location
void updateScreen(unsigned int location) {
    int x = getmaxx(stdscr);
    int y = getmaxy(stdscr);

    // reset cursor to top left
    move(0, 0);

    // print out lines from location to location + y, leaving one for status bar
    int lineNumber = location;
    
    char *line = (char *) malloc(LINE_LENGTH * sizeof(char));
    lseek(fileno(inFile), lineNumber, SEEK_SET);
    while (lineNumber < location + y - 1 && fgets(line, LINE_LENGTH, inFile)) {
        printw("%s", line);
        lineNumber++;
    }

    // print out status bar at the bottom
    printw("location: %d", location);
    
    refresh();
}

int main(int argc, char **argv) { 
    if (argc < 2) {
        printf("no input file specified\n");
        return 1;
    }
    inFile = fopen(argv[1], "r");
    if (!inFile) {
        printf("failed to open file: %s\n", argv[1]);
    }

    initialize();

    signal(SIGINT, sigintHandler); // set SIGINT handler

    unsigned int location = 0; // "y" coordinate from top of file

    int ch;
//    int y = 1234;
//    int x = 1234;
    while (1) {
        ch = getch();
//        y = getcury(stdscr);
//        x = getcurx(stdscr);
        //printw("maxy: %d, maxx: %d\n", getmaxy(stdscr), getmaxx(stdscr));
        //printw("cury: %d, curx: %d\n", getcury(stdscr), getmaxx(stdscr));
        //refresh();

        if (ch == 'j') {
            location++;
        } else if (ch == 'k' && location != 0) {
            location--;
        } else if (ch == 'q') {
            endProgram();
        }
        
        updateScreen(location);
    }

    endProgram();

    return 0;
}
