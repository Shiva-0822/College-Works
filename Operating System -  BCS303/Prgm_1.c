/* Develop a c program to implement the Process system calls (fork (), exec (), wait (),
create process,terminate process). */

#include <stdio.h>     // printf()
#include <stdlib.h>    // exit()
#include <sys/types.h> // pid_t
#include <sys/wait.h>  // wait() This headers and librarys present in unix and linux based systems use wsl to get this in windows
#include <unistd.h>    // fork
int main(int argc, char **argv)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("It is the child process and pid is %d\n", getpid());
        int i = 0;
        for (i = 0; i < 8; i++)
        {
            printf("%d\n", i);
        }
        exit(0);
    }
    else if (pid > 0)
    {
        printf("It is the parent process and pid is %d\n", getpid());
        int status;
        wait(&status);
        printf("Child is reaped\n");
    }
    else
    {
        printf("Error in forking..\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}