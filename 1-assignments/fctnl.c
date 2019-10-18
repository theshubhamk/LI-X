#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDWR | O_APPEND);
 
    struct flock lock;
    memset (&lock, 0, sizeof(lock));


    pid_t x;
    x = fork();
    if(x == 0)
    {
    	dup2(fd,1);
        lock.l_type = F_WRLCK;
        fcntl (fd, F_SETLKW, &lock);

        //
        //printf("child process....\n");
        int a = 2;
        for(int i = 0; i < 20; i++)
        {
          //  a += a;
            printf("%d\n",a);
        }

        lock.l_type = F_UNLCK;
        fcntl (1, F_SETLKW, &lock);
    }
    else
    {
    	dup2(fd,1);
        lock.l_type = F_WRLCK;
        fcntl (fd, F_SETLKW, &lock);
        //sleep(1);
        //

        int b = 3;
        for(int i = 0; i < 20; i++)
        {
          //  b += b;
            printf("%d\n",b);
        }
    
        //printf("parent process\n");
        lock.l_type = F_UNLCK;
        fcntl (1, F_SETLKW, &lock);
    }
    
    
//wait(NULL);
}