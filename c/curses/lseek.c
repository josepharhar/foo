#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* inFile = fopen(argv[0], "r");
    if (!inFile) {
        printf("dun goofed\n");
        return 1;
    }

    char input[1];
    int location = 0;
    int filedes = fileno(inFile);
    char* lineBuffer = (char*) malloc(4096 * sizeof(char));

    scanf(" %c", input);
    while (*input != 'q') {

        if (*input == 'j') {
            // go down
            location++;
        } else if (*input == 'k') {
            // go up
            if (location > 0) {
                location--;
            }
        }

        lseek(filedes, SEEK_SET, location);
        fgets(lineBuffer, 4096, inFile);

        printf("lseek to: %d\n", location);
        printf("%s\n", lineBuffer);


        scanf(" %c", input);
    }

    return 0;
}
