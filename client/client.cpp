//
// Created by lidor on 12/27/22.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int checkValidPort (const string& s);
bool wantToContinue(string s);
/**
 * this function response the connection between the client and the server.
 * @param argc , number of arguments.
 * @param argv  , array of arguments.
 * @return
 */
int main(int argc,char* argv[]) {
    if(argc!=3){
        cout<<"the number of arguments passed is invalid"<<endl;
        return 0;
    }
    const char *ip_address = argv[1];
    const int port_no = checkValidPort(argv[2]);
    if (port_no < 0) {
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
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return 0;
    }
    while (true) {
        cout << "enter data:" << endl;
        string input;
        getline(cin, input);
        while (input.length()==0)
        {
            cout << "invalid input" << endl;
            cout << "enter data:" << endl;
            getline(cin, input);
        }
        bool answer = wantToContinue(input);
        char *data_addr = (char*)(input.c_str());
        int data_len = input.length();
        data_addr[data_len]='\n';
        data_len++;
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            cout<<"error has occurred"<<endl;
            exit(0);
        }
        char buffer[4096]= {0};
        int expected_data_len = sizeof(buffer);
        if (answer) {
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                cout<<"connection is closed"<<endl;
                break;


            } else if (read_bytes < 0) {
                cout<<"error has occurred"<<endl;
                break;
            } else {
                cout << buffer<<endl;
            }
        } else {
            break;
        }
    }
        close(sock);
        return 0;
    }
/**
 * check if the port are valid.
 * @param s , string of port.
 * @return , if valid return the integer port , if not return -1.
 */
int checkValidPort (const string& s){
    for(char i : s){
        if(!isdigit(i))
            return -1;
    }
    int port=stoi(s);
    if(port<65536)
        return port;
    return -1;
}
/**
 * check if the client want to continue the specified the vectors.
 * @param s , the string of client
 * @return -1 if want to stop  the specified.
 */
bool wantToContinue(string s){
    return !(s=="-1");
}

