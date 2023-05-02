#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void child()
{
    printf("I am child! my pid is: %d\n", getpid());
    while (1)
        ;
}

void parent(int pid)
{
    int status;

    printf("I am parant! my pid is: %d\n", getpid());
    waitpid(pid, &status, 0);
    printf("some text from parent\n");
}

int main(int argc, char **argv)
{
    int pid;
    
    printf("pid = %d\n", getpid());
    pid = fork();
    if (pid == 0)
        child();
    else
        parent(pid);
}
