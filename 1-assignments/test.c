#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

//int fstat(int fd, struct stat *statbuf);
int file_op(int *fd1, int *fd2, char *argv[]);
int word_count (int fd, int *lines, int *words, int *bytes); 


int main(int argc, char *argv[])
{
    int flagg = 1;
    int i;
    //Arg check
    for(i = 0; i < argc;i++)
    {
        //printf("dw\n");
        if((*argv[i] == '|'))// && (*argv[i+1] != '\0'))
        {   
            int k = i + 1;
            flagg = 0;
            if((*argv[argc - 1] == '|'))
            {
                flagg = 1;
            }
        }
        
        
    }
    printf("%d", flagg);
    if(flagg == 1)
    {
        printf("Error: No arguments passed\nUsage: ./pipe <command 1> | <command 2>\n");
        exit(0);
    }

	return 0;
}


    