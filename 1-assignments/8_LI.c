#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/wait.h>

int main()
{
    int rett, rett1, rett2;
    int pid1, pid2, pid3;
    int status;
    rett = fork();
    if(rett == 0)
    {
        pid1 = getpid();
        printf("This is child 1 with PID %d\n", getpid());
        sleep(2);
    }
    else
    {
        //sleep(1);
        int rett1 = fork(); 
        if(rett1 == 0)
        {
            pid2 = getpid();
            printf("This is child 2 with PID %d\n", getpid());
            sleep(5);
        }
        else
        {
            int rett2 = fork();
            if(rett2 == 0)
            {
                pid3 = getpid();
                printf("This is child 3 with PID %d\n", getpid());
                sleep(10);
            }
            else
            {
                int p_id;
                while((p_id = wait(&status)) != -1)
                {
                    if(WIFEXITED(status))
                    {
                        printf("child %d terminated normally\n", p_id);
                        printf("child ststus %d\n",  WEXITSTATUS(status));
                    }
                }
            }
        }
        
    }
    
    return 0;
}