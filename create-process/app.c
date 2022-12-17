#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t forkReturn;

  printf("Hello, I'm the initial PARENT process %5d\n", getpid());

  printf("Before: fork() \n");

  forkReturn = fork(); // value < 0 -> Error || value = 0 -> CHILD process || value > 0 -> PARENT process

  printf("After: fork() \n");

  printf("[forkReturn=%5d] I'm the process of ID=%5d, child of ID=%5d\n", forkReturn, getpid(), getppid());

  if (forkReturn < 0)
  {
    perror("Error");
    exit(1);
  }
  else if (forkReturn > 0)
  {
    // wait(0);
    printf("I'm the PARENT process running -- ");
    printf("product result of multiplication: %d *** ", 3 * 3);
  }
  else
  {
    sleep(5);
    printf("I'm the CHILD process running -- ");
    printf("sum result of addition: %d *** ", 2 + 2);
  }

  printf("End of process ID=%5d!\n", getpid());
  exit(0);
}
