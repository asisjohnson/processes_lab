#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    srandom(time(NULL));

    pid_t child_pid1, child_pid2;

    // Child Process 1
    child_pid1 = fork();

    if (child_pid1 == 0) {
        int iterations1 = (random() % 30) + 1;
        for (int i = 0; i < iterations1; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep((random() % 10) + 1);
            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
        }
        // Exit
        exit(0);
    } else if (child_pid1 < 0) {
        perror("Fork 1 failed");
        exit(1);
    }

    // Child Process 2
    child_pid2 = fork();

    if (child_pid2 == 0) {
        int iterations2 = (random() % 30) + 1;
        for (int i = 0; i < iterations2; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep((random() % 10) + 1);
            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
        }
        // Exit
        exit(0);
    } else if (child_pid2 < 0) {
        perror("Fork 2 failed");
        exit(1);
    }

    // Parent Process
    int status1, status2;
    wait(&status1);
    printf("Child Pid: %d has completed\n", child_pid1);

    wait(&status2);
    printf("Child Pid: %d has completed\n", child_pid2);

    return 0;
}