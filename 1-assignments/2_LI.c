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
    int retval;
    char *inp = malloc(sizeof(char) * 100);
    struct stat *statbuf;
    char *arr[3];
    int flagg = 0;
    arr[0] = "wc";
    arr[1] = NULL;
    arr[2] = NULL;
    arr[3] = NULL;
    arr[4] = NULL;
   // char *buff = (char *) malloc(sizeof(char) * 100);
    char *buff = (char *) calloc(100, sizeof(char));

    int *fd1 = malloc(sizeof(int) * 100);// = open(argv[1], O_RDWR | O_EXCL );
    int *fd2 = malloc(sizeof(int) * 100);
    int *fd = malloc(sizeof(int) * 100);
    int *lines, *words, *bytes;

    if(argc == 1)
    {
        //arr[1] = "-m";
        //scanf("%s", inp);
        execvp(arr[0],arr);
        //execl("/usr/bin/wc","wc",inp,(char *)NULL);
    }
    else
    {
        //arr[1] = argv[1];
        //strcpy(arr[1],argv[1]);
        //printf("%c", argv[1][1]);
        printf("gg\n");
        if(argc == 4 && (argv[1][0] == '-') && (argv[2][0] == '-') && (argv[3][0] == '-')) //(strcmp(&argv[1][0],"-") == 0) && (strcmp(&argv[2][0],"-") == 0) && (strcmp(&argv[3][0],"-") == 0) )
        {
            printf("1\n");
            arr[1] = argv[1];
            arr[2] = argv[2];
            arr[3] = argv[3];
            execvp(arr[0],arr);
        }
        else if(argc == 3 && (argv[1][0] == '-') && (argv[2][0] == '-'))
        {
            printf("lslskda\n");
            arr[1] = argv[1];
            arr[2] = argv[2];
            execvp(arr[0],arr);
            exit(1);
        }
        else if(argc == 2 && (argv[1][0] == '-'))
        {
            arr[1] = argv[1];
            execvp(arr[0],arr);
        }
        else
        {
            printf("enetr\n");
            int l;
            if((argv[1][0] == '-') && (argv[2][0] == '-') && (argv[3][0] == '-'))
            {
                printf("1\n");
                argv[1] = "-l";
                argv[2] = "-w";
                argv[3] = "-c";
                l = 4;
            }
            else if((argv[1][0] == '-') && (argv[2][0] == '-'))
            {
                printf("lslskda\n");

                l = 3;
            }
            else if((argv[1][0] == '-'))
            {
                l = 2;
            }
            else
            {
                l = 1;
            }
            
            for(;l <= argc; l++)
            {
                *fd = open(argv[l], O_RDWR | O_EXCL );
                int k = fork();
                if(k == 0)
                {
                    printf("%d", getppid());
                    execl("/usr/bin/wc", "wc", argv[l], (char *)NULL);
                }
                else
                {
                    wait(NULL);
                    //sleep(1);

                }
                
                //word_count(fd, &lines, &words, &bytes);
            // printf("%d %d %d", &lines, &words, &bytes);
            }
        }
        
        /*else if((strcmp(argv[1],"-l") == 0) || (strcmp(argv[1],"-m") == 0) || (strcmp(argv[1],"-c") == 0))
        {
            arr[1] = argv[1];
            execvp(arr[0],arr);
        }*/
        //execl("/usr/bin/wc", "wc", argv[1], (chexecvp(arr[0],arr);ar *)NULL);
    }
    
    

    

   printf("dqwdwq");


    close(*fd1);
    close(*fd2);
	return 0;
}

int word_count (int fd, int *lines, int *words, int *bytes)
{
    ;
}
int file_op(int *fd1, int *fd2, char *argv[])
{
    if(*fd2 == -1)
    {
        *fd2 = open(argv[2], O_RDWR | O_CREAT );
        perror("r1");
    }
    else
    {
        printf("file already present\nDo you want to overwrite? (Y/N)\n");
        char k = getchar();
        if(k == 'Y' | k == 'y')
        {
            *fd2 = open(argv[2], O_RDWR | O_CREAT );
        }
        else
        {
            printf("Not overwritten");
            exit(1);
        }
            
    }
    return 0;      
}
