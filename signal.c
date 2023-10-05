/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int counter = 0

void handler(int signum)
{ //signal handler
  if (count == 0)
  {
    printf("Hello World!\n");
    counter = 1;
  }
  else
  {
    printf("Turning was right!\n");
    counter = 0;
  }
  alarm(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1); //busy wait for signal to be delivered
  {
    sleep(2);
  }
  return 0; //never reached
}