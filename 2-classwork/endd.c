#include <stdio.h>
#include <stdlib.h>

void endiann(char *, char *);

int main()
{   
    char value[3];
    int i = 0;
    printf("Enter a value\n");
    for(i = 0;i <3;i++)
    {
    	scanf("%c",value);
    }
    //char value[3] = "8D";
    char *ptr;
    ptr = (char *)&value;
    
    printf ("%p has %c\n", ptr, *ptr);
    endiann(ptr,value);
   // ptr = ptr + sizeof(char);
   // printf ("%p has %c\n", ptr, *ptr);
}

void endiann(char *ptr,char *value)
{

    if (*ptr == *value)
    {
         printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
}