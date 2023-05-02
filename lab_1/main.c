#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signal)
{
    if (signal == SIGTERM)
    {
        printf("*********SIGTERM********\n");
        exit(0);
    }
    if (signal == SIGUSR2)
        printf("*********SIGUSR2********\n");
}

int main(int argc, char **argv)
{
    printf("pid = %d\n", getpid());
    while(1)
    {
        signal(SIGTERM, &sig_handler);
        signal(SIGUSR2, &sig_handler);
    }
}
