#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LINE_LENGTH 4096

int main(int argc, char** argv) {

    // check command line arguments
    int isInputPiped = 0;
    int numArgs = 3;
    //fileno() gets the file descriptor of the stream
    if (!isatty(fileno(stdin))) {
        isInputPiped = 1;
        numArgs--;
    }
    if (argc != numArgs) {
        printf("Incorrent number of arguments\n");
        return 1;
    }

    // get regex from input
    char* regex = argv[1];

    // get input file from stdin or by opening file
    FILE* inFile = NULL;
    if (isInputPiped) {
        inFile = stdin;
    } else {
        inFile = fopen(argv[2], "r");
        if (!inFile) {
            printf("Failed to open file: %s\n", argv[2]);
        }
    }

    // line buffer
    char* line = (char*) malloc(LINE_LENGTH * sizeof(char));

    // print each line if contains regex
    int i = 0;
    while (fgets(line, LINE_LENGTH, inFile)) {
        if (strstr(line, regex)) {
            printf("line %d: %s", i, line);
        }
        i++;
    }

    // close the file
    fclose(inFile);
}
