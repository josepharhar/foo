#include <signal.h>
#include <stdio.h>

static volatile int keepRunning = 1;

void sigintHandler(int dummy) {
    printf("Captured a SIGINT!\n");
    keepRunning = 0;
}

void sigtermHandler(int dummy) {
    printf("Captured a SIGTERM!\n");
    keepRunning = 0;
}

int main() {
    signal(SIGINT, sigintHandler);
    signal(SIGTERM, sigtermHandler);

    while (keepRunning);

    return 0;
}
