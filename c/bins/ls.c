#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char** argv) {

    DIR* directory = opendir(".");

    if (!directory) {
        printf("directory is NULL\n");
        return 1;
    }

    // represents a single entry in the directory
    struct dirent* entry;
    int i = 0;
    while (entry = readdir(directory)) {
        printf("entry %d: %s\n", i, entry->d_name);
        i++;
    }

    closedir(directory);

    return 0;

}
