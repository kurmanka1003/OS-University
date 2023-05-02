#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int     fd;
    char    *buf;

    fd = open("./my_pipe", O_RDWR);
    while(1)
    {
        buf = malloc(sizeof(char) * 255);
        read(fd, buf, 255);
        printf("buf = %s", buf);
        free(buf);
    }
}
