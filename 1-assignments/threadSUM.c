#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct 
{
    char *baseaddress;
    int elements;
}sumdata_t;

void *sum_func(void *param)
{
    int *ptr = malloc(sizeof(int));
    *ptr = 0;
    sumdata_t *info = param;
    
    int i;
    for(i = 0; i < 4; i++)
    {
        *ptr = (*(info->baseaddress)- 48) + *ptr; //info->baseaddress is just accessing the member {of the respective struct} called baseadress which is having an address and thus (info->baseaddress) is also an address and *(info->baseaddres) is the value at that address.
        (info->baseaddress)++;
    }
    return ptr;
    // we are returning address here.
}

int main(int argc, char *argv[])
{
    pthread_t tid[4]; //thread ID
    //struct kum data; ==  sumdata_t data;
    sumdata_t data[4];
//    data.num2 = 10, data.num1 = 5;
      int *sum = NULL;  
    data[0].baseaddress = &argv[1][0];
    data[1].baseaddress = &argv[1][4];
    data[2].baseaddress = &argv[1][8];
    data[3].baseaddress = &argv[1][12];
    data[0].elements = 4;
    data[1].elements = 4;
    data[2].elements = 4;
    data[3].elements = 4;
    int add = 0;
    //create thread 1 . thread 1 will execute sum_func . Argc is &data
    for(int i = 0; i < 4; i++)
    {
        pthread_create(&tid[i], NULL, sum_func, &data[i]);
    }

    //wait for the thread 1 to complete using pthread_join
    for(int i = 0; i < 4; i++)
    {
        pthread_join(tid[i],(void **) &sum);

        printf("Sum = %d\n", *sum);
        add = add + *sum;
    }   
    //print the result
    printf("total Sum = %d\n", add);

    //free ptr
    free(sum);
    sum = NULL;

    return 0;
}