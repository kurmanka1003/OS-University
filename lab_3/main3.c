#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void    *pthread_work1(void *args)
{
    char *data = (char*)args;

    printf("\t**hello from first thread!**\ndata = %s; pid = %d\n", data, getpid());
    for (int i = 0; i < atoi(args); i++)
    {
        printf("data = %s; i = %d\n", data, i);
        sleep(3);
    }
    printf("\t**end of loop in first thread**\n");
}

void    *pthread_work2(void *args)
{
    char *data = (char*)args;

    printf("\t**hello from second thread!**\ndata = %s; pid = %d\n", data, getpid());
    for (int i = 0; i < atoi(args); i++)
    {
        printf("data = %s; i = %d\n", data, i);
        sleep(3);
    }
    printf("\t**end of loop in second thread**\n");
}

int main(int argc, char **argv)
{
    pthread_t *pthread_id = malloc(sizeof(pthread_t) * 2);
    int pid;
    
    if (argc != 3)
    {
        printf("error\n");
        exit(-1);
    }

    printf("\t**start of main!**pid = %d\n", getpid());
    pthread_create(&pthread_id[0], NULL, pthread_work1, argv[1]);
    pthread_create(&pthread_id[1], NULL, pthread_work2, argv[2]);
    pthread_join(pthread_id[0], NULL);
    printf("\t**end of main**; pid = %d\n", getpid());
}
