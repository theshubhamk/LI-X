#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void my_signal_handler(int signum)//, struct sigaction new_act)
{
    printf("got signal %d\n", signum);
    
    exit(0);
}

void handler(int signum, siginfo_t *infooo, void *ucontext)
{
    printf("got signal using signum %d\n", signum);
    //printf("got signal %d\n", infooo->si_pid);
    printf("Address %p caused error\n",infooo->si_addr);
    signal(SIGSEGV, SIG_DFL);
}
int main(int argc, char *argv[])
{
    struct sigaction new_act;
    memset(&new_act, 0, sizeof(new_act));
    //new_act.sa_handler = my_signal_handler;
    sigemptyset (&new_act.sa_mask);
    new_act.sa_flags = SA_SIGINFO | SA_RESTART;

    new_act.sa_sigaction = (void *)handler;
    sigaction(SIGSEGV, &new_act, NULL);


    char *arr[5];
    arr[6] = NULL;
    int count = 0, k;
    int *p;
    int *l;
    //while(1)
    {
        count++;
        sleep(1);
        printf ("PID: %d\n", getpid());
        //printf("loop run instance %d\n", count);
       // if(count == 5)
        {
            
            char *str;  
  
            /* Stored in read only part of data segment */
            str = "GfG";      
            
            /* Problem:  trying to modify read only memory */
            *(str+1) = 'n';
        }
    }
    return 0;
}
