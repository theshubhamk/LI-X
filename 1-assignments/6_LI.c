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
    int rret = fork();
    int p_id;
    int status;
    int i;
    if(rret == 0)
    {
        p_id = getpid();
        printf("A child is created with PID %d\n", getpid());
        //sleep(10);
    }
    else
    {
        sleep(1);
        //printf("A child is created with PID in s %d\n", p_id);
        int pd = waitpid(rret, &status, WNOHANG);
        //int pd = wait(&status);
        for(i = 0;i < 5;i++)
        {
            printf("parent running..\n");
            sleep(1);
        }
        //while(pd != -1)
        if(pd != -1)
        {
            if(WIFEXITED(status))
            {
                printf("child %d terminated normally\n", pd);
                printf("child ststus %d\n",  WEXITSTATUS(status));
            }
        }        
    }
    
    /*
    //while(rret != 0 && rret != -1)
    //else
    {
      //  printf("Parent is running..\n");
        
    }
    
    int sta = waitpid(p_id, &status, WNOHANG);
    if(sta != -1 && sta != 0)
    {
        if(WIFEXITED(status))
        {
            printf("child %d terminated normally\n", p_id);
            printf("child ststus %d\n",  WEXITSTATUS(status));
        }
    }*/
    return 0;
}