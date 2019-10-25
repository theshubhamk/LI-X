#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//define the shared mem size
#define SIZE 100

int main()
{
    int shmid , num;
    int *shm;
    key_t key;

    //key can be hardcoded but use the same in reader and writer

    key = 'B';

    //create a shared mem
    shmid = shmget(key, SIZE, IPC_CREAT | 0600);

    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }
    else
    {
        printf("created SHM with ID = %d\n", shmid);
        shm = shmat(shmid, NULL, 0);

        printf("Enter the number\n");
        scanf("%d", &num);

        *shm = num;
        
        //detach from shm
        //shmdt(shm);
    }
    
}