#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8888

int main(int argc, char* argv[]) {
    struct sockaddr_in server;
    struct sockaddr_in client;
    int s_wait;
    int s;
    unsigned char* client_addr;
    int client_len;
    char buf[128];

    s_wait = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *)&server, sizeof(server));
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = PORT;
    bind(s_wait, (struct sockaddr*)&server, sizeof(server));

    listen(s_wait, 5);

    client_len = sizeof(client);
    s = accept(s_wait, (struct sockaddr*)&client, &client_len);
    close(s_wait);

    client_addr = (unsigned char*)&(client.sin_addr.s_addr);
    printf("connected to %d.%d.%d.%d.\n",
           client_addr[0], client_addr[1],
           client_addr[2], client_addr[3]);

    sprintf(buf, "Hello, %d.%d.%d.%d!\n",
            client_addr[0], client_addr[1],
            client_addr[2], client_addr[3]);
    write(s, buf, strlen(buf));

    close(s);

    return 0;
}
