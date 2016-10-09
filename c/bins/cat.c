#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 4096

int main(int argc, char **argv) {

    /* Verify command line arguments */
    if (argc < 2) {
        printf("No file specified!\n");
        return 1;
    }

    /* Open input file for reading */
    FILE* inFile = fopen(*(argv + 1), "r");

    /* Verify file was opened */
    if (inFile == NULL) {
        printf("Failed to open file: %s\n", *(argv + 1));
        return 1;
    }

    /* Input buffer. LINE_LENGTH max characters per line, 4KB ram */
    char* buffer = (char*) malloc(LINE_LENGTH * sizeof(char));

    /* read file one line at a time, printing each line to stdout */
    char* line = (char*) malloc(LINE_LENGTH * sizeof(char));
    while (fgets(line, LINE_LENGTH, inFile)) {
        printf("line strlen: %zd\n", strlen(line));
        printf("%s", line);
    }

    /* close file stream */
    fclose(inFile);
}
