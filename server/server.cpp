//#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <csignal>
#include "Tools.h"
#include "ClassifiedArray.h"
#include "run_main.h"
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
    if(argc!=3){
        cout<<"the number of arguments passed is invalid"<<endl;
        return 0;
    }
    const int server_port=checkValidPort(argv[2]);
    if (server_port<0) {
        cout << "invalid port!\n";
        exit(0);
    }
    string path = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
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
    ClassifiedArray x = ClassifiedArray(std::move(path));
    x.PopulateVector();
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        while (true) {
            char buffer[4096] = {0};
            int expected_data_len = sizeof(buffer);
            string s="";
            int read_bytes;
            do {
                read_bytes = recv(client_sock, buffer, expected_data_len, 0);
                if (read_bytes < 0) {
                    close(client_sock);
                    break;
                }
                s=s.append(buffer);

            } while (buffer[read_bytes-1]!='\n');
            if(read_bytes==3){
                if(s=="-1\n"){
                    close(client_sock);
                    break;
                }
            }
            int length=s.size();
            char *full = (char*)(s.c_str());
            full[length-1]='\0';
            string message=RunMain::runMain(full,x);
            const char* toSend=message.c_str();
            int sent_bytes = send(client_sock,toSend, message.size(), 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
    }
}