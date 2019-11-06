
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_IP       "127.0.0.1"
#define SERVER_PORT 	8085
#define SERVER_LENGTH 	10
#define SERVER_BUFF	20

int main()
{

    int sock_fd, data_sock_fd,buffer_len, c_size;
    struct sockaddr_in serv_addr; 
    char serv_buffer[SERVER_BUFF];

    printf("Server is waiting...\n");

    /* Create a TCP socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Bind it to a particular IP address & port) */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT); 

    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    /* listen for incoming connections */
    listen(sock_fd, SERVER_LENGTH);

    /* If there are any, accept and create a new data socket */
    data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL); 

    memset(serv_buffer, 0, sizeof(serv_buffer));
    /* Try to get some actual data from client */
    recv(data_sock_fd, (void *) serv_buffer,SERVER_BUFF,0);
    
    char *num1, *num2;
    num1 = strtok(serv_buffer, "+");
    num2 = strtok(NULL, "+");
    
    int res = atoi(num1) + atoi(num2);
    char k[10];
    //k[0] = res - '0'; 
    printf("Result sum %d\n", res);
    sprintf(k, "%d", res);
    printf("res in string %s\n", k);
    c_size = send(data_sock_fd, k, 10, 0);
    
    if(c_size > 0)
	printf("socket sent to server successsfully, please check\n");
    else
	printf("Error: Message send\n");

    /* Close the sockets now */
    close(data_sock_fd);
    close(sock_fd);
}
