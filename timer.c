#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile int alarms = 0;
time_t start_time;

void alarm_handler(int signum) {
    if (alarms == 0) {
        printf("Hello World!\n");
    } else {
        printf("Turning was right!\n");
    }
    alarms++;
    alarm(1);
}

void ctrlc_handler(int signum) {
    time_t end_time = time(NULL);
    double execution_time = difftime(end_time, start_time);

    printf("\nProgram executed for %.2f seconds.\n", execution_time);
    printf("Number of alarms: %d\n", alarms);
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, ctrlc_handler);

    alarm(1); 
    start_time = time(NULL);

    while (1) {
        
    }

    return 0;
}