#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

void write_to_pipe(int fd)
{
    char    *s;

    srand(time(NULL));
    s = malloc(sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        s[0] = rand()%26 + 'A';
        write(fd, s, 1);
        sleep(5);
    }
    exit(0);
}

void read_from_pipe(int fd)
{
    char    *buf;
    int     status;

    for (int i = 0; i < 5; i++)
    {
        buf = malloc(sizeof(char));
        read(fd, buf, 1);
        printf("buf = %s\n", buf);
        free(buf);
    }
}

int main()
{
    int     pipe_fd[2];

    pipe(pipe_fd);
    if (fork() != 0)
        read_from_pipe(pipe_fd[0]);
    else
        write_to_pipe(pipe_fd[1]);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}
