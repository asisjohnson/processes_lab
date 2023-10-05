#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile int counter = 0;
time_t start_time;

void handler(int signum){ //signal handler
  if (counter == 0) {
    printf("Hello World!\n");
    counter = 1;
  } else {
    printf("Turning was right!\n");
    counter = 0;
  }
  counter++;
  alarm(1);
}

void ctrlc_handler(int signum) {
    time_t end_time = time(NULL);
    double execution_time = difftime(end_time, start_time);

    printf("\nProgram executed for %.2f seconds.\n", execution_time);
    printf("Number of alarms: %d\n", counter);
    exit(0);
}

int main() {
    signal(SIGALRM, handler);
    signal(SIGINT, ctrlc_handler);

    alarm(1); 
    start_time = time(NULL);

    while (1) {
        
    }

    return 0;
}