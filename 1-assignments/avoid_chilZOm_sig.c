#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void my_signal_handler(int signum)//, struct sigaction new_act)
{
    //printf("got signal %d\n", signum);
    wait(NULL);
    //exit(0);
}

void handler(int signum, siginfo_t *infooo, void *ucontext)
{
    printf("got signal using signum %d\n", signum);
    printf("got signal %d\n", infooo->si_pid);
    printf("Address %p caused error\n",infooo->si_addr);
    exit(0);
}
int main(int argc, char *argv[])
{
    struct sigaction new_act;
    memset(&new_act, 0, sizeof(new_act));
    new_act.sa_handler = (void *)my_signal_handler;
    //sigemptyset (&new_act.sa_mask);
    //new_act.sa_flags = SA_SIGINFO | SA_RESTART;

    //new_act.sa_sigaction = (void *)handler;
    sigaction(SIGSEGV, &new_act, NULL);


    char *arr[5];
    arr[6] = NULL;
    int count = 0, k;
    int *p;
    int *l;
    //while(1)
    {
        int x = fork();
        if(x == 0)
        {
        	//sleep(5);
            for(int i = 0; i < 20;i++)
            {
                printf("child is %d\n", getpid());
            }
        }
        else
        {
            //sleep(1);
            //wait(NULL);
            
            signal(SIGCHLD,my_signal_handler);
            sleep(1);
            //for(int i = 0; i < 20;i++)
            {
                printf("parent is %d\n", getpid());
                while(1);
            }
        }
        perror("forkk:");
    }
    return 0;
}
