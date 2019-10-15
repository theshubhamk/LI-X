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

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Enter valid CL inputs\nUsage:\n./exe_child args...\n");
        exit(0);
    }
    int rret = fork();
    int p_id;
    int status;
    int i;
    char *arr[2];
    arr[0] = argv[1];
    arr[1] = NULL;
    
    if(rret == 0)
    {
        printf("A child is created with PID %d\n\n", getpid());
        printf("-------------------------------STARTING EXECUTION-----------------------------------\n\n");
        if(execvp(arr[0],arr) == -1)
        {
            perror("EXECUTION ERROR WITH MESSAGE");
            printf("\t\t\t\tEnter a valid command\n");
            exit(1);
        }
        //sleep(10);
    }
    else
    {
        sleep(1);
        //printf("A child is created with PID in s %d\n", p_id);
        //int pd = waitpid(rret, &status, WNOHANG);
        int pd = wait(&status);
        //for(i = 0;i < 5;i++)
        //{
          //  printf("parent running..\n");
          //  sleep(1);
        //}
        //while(pd != -1)
        if(pd != -1)
        {
            if(WIFEXITED(status))
            {
                printf("\n--------------------------------ENDING EXECUTION------------------------------------\n");
                printf("\nchild %d terminated normally\n", pd);
                printf("child ststus %d\n",  WEXITSTATUS(status));
            }
        }        
    }
    return 0;
}