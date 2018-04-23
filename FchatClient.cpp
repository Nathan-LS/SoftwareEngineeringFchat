#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    int client, server;
    int portNum = 2403;
    int bufsize = 2048;
    char buffer[bufsize];
    char *ip = "127.0.0.1";

    struct sockaddr_in server_addr;
    // init socket

    client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0){
        cout << "Error no server connection"
        exit(1);
    }

    cout << "Client Socket created" << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    //connecting to socket server

    if(connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0){
        cout << "Connecting to server..." endl;
    }

    recv(client, buffer, bufsize, 0);
    cout << "Confimed Connection" << endl;


    return 0;
}