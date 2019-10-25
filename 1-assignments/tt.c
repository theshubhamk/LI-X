#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//volatile sig_atomic_t print_flag = false;
int flag = 0;
void handle_alarm( int sig ) 
{
    //print_flag = true;
    flag = 1;
    printf("dsdsd\n");
}

int main() 
{
    signal( SIGALRM, handle_alarm ); // Install handler first,
    alarm(2); // before scheduling it to be called.

    for (;;) 
    {
        //if ( print_flag ) 
        if(flag)
        {
            printf( "Hello\n" );
            //print_flag = false;
            flag = 0;
            alarm( 2 );
        }
    }
}