//#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <csignal>
#include "Tools.h"
#include "ClassifiedArray.h"
#include "../IO/DefaultIO.h"

#include "../command/CLI.h"
#include "../IO/StandardIO.h"
#include "../IO/SocketIO.h"
//
// Created by lidor on 12/26/22.
//
using namespace std;
/**
 * this function response the connection between the server and client.
 * @param argc , number of arguments.
 * @param argv , array of arguments.
 * @return
 */
int main(int argc,char* argv[]) {
    if(argc!=2){
        cout<<"the number of arguments passed is invalid"<<endl;
        return 0;
    }
    const int server_port=checkValidPort(argv[1]);
    if (server_port<0) {
        cout << "invalid port!\n";
        exit(0);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 0;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        DefaultIO *def = new SocketIO(client_sock);
        //DefaultIO *def = new StandardIO();
        //string massage = def->read();
        CLI cli = CLI(def);
        cli.start();
    }
}