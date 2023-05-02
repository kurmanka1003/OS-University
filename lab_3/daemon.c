#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void sig_handler(int signal)
{
    if (signal == SIGTERM)
    {
        syslog(LOG_INFO, "DEMON IS TERMINATED(((");
        closelog();
        exit(0);
    }
    else if (signal == SIGHUP)
        syslog(LOG_INFO, "DAEMON GOT HUP...");
}

void Daemon()
{
    setsid();
    umask(0);
    chdir("/");
    freopen( "/dev/null", "r", stdin);
    freopen( "/dev/null", "w", stdout);
    freopen( "/dev/null", "w", stderr);

    openlog("laba3", LOG_PID, LOG_USER);
    syslog(LOG_INFO, "DEMON IS STARTED AHAHAHAH");
    while(1)
    {
        signal(SIGTERM, &sig_handler);
        signal(SIGHUP, &sig_handler);
    }

    
}

int main()
{
    int pid;

    pid = fork();
    if (pid != 0)
    {   exit(1); }
    Daemon();
    while(1)
        ;
}
