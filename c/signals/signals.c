#include <stdio.h>
#include <signal.h>

void HandleSIGHUP(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGINT(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGQUIT(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGABRT(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGTERM(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGCHLD(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGCONT(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGSTOP(int signal) {
  printf("%s\n", __FUNCTION__);
}

void HandleSIGTSTP(int signal) {
  printf("%s\n", __FUNCTION__);
}

int main(int argc, char** argv) {

  signal(SIGHUP, HandleSIGHUP);
  signal(SIGINT, HandleSIGINT);
  signal(SIGQUIT, HandleSIGQUIT);
  signal(SIGABRT, HandleSIGABRT);
  signal(SIGTERM, HandleSIGTERM);
  signal(SIGCHLD, HandleSIGCHLD);
  signal(SIGCONT, HandleSIGCONT);
  signal(SIGSTOP, HandleSIGSTOP);
  signal(SIGTSTP, HandleSIGTSTP);

  while (1) {}

  return 0;
}
