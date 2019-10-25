// C program to demonstrate 
// ctime() function. 
#include <stdio.h> 
#include <time.h> 

int main () { 
	time_t curtime, x; 
	
	x = time(&curtime); 
	printf("%ld\n", x);
	printf("Current time = %s", ctime(&x)); 
	
	return(0); 
} 
