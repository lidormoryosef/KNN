//
// Created by lidor on 12/27/22.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include "../IO/SocketIO.h"
#include "../IO/StandardIO.h"
using namespace std;
int checkValidPort (const string& s);
bool wantToContinue(string s);
bool IsValidK(const string& s);
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
        DefaultIO *dio=new SocketIO(sock);
        DefaultIO *local=new StandardIO();
        string choice,path,file="",temp,params;
        int pick;
        fstream fin;
        local->write(dio->read());
        choice=local->read();
        if(IsValidK(choice)){
            pick=stoi(choice);
            dio->write(choice);
            switch(pick) {
                case 1:
                    path = local->read();
                    fin.open(path, ios::in);
                    if (!fin) {
                        cout << "invalid path!" << endl;
                        break;
                    }
                    while (getline(fin, temp)) {
                        file.append(temp);
                    }
                    dio->write(file);
                    local->write(dio->read());
                    path = local->read();
                    fin.close();
                    fin.open(path, ios::in);
                    if (!fin) {
                        cout << "invalid path!" << endl;
                        break;
                    }
                    while (getline(fin, temp)) {
                        file.append(temp);
                    }
                    dio->write(file);
                    local->write(dio->read());
                    fin.close();
                    break;
                case 2:
                    local->write(dio->read());
                    params=local->read();
                    dio->write(params);
                    break;
                case 3:
                    local->write(dio->read());
                    break;
                case 4:
                    local->write(dio->read());
                    break;
                case 5:
                    path = local->read();
                    fin.open(path, ios::out);
                    if (!fin) {
                        cout << "invalid path!" << endl;
                        break;
                    }
                    fin << dio->read();
                    fin.close();
                    break;
                default:
                    break;
            }
            if(pick==8){
                close(sock);
                break;
            }
            }

        }
//        char buffer[4096]= {0};
//        int expected_data_len = sizeof(buffer);
//        if (answer) {
//            int read_bytes = recv(sock, buffer, expected_data_len, 0);
//            if (read_bytes == 0) {
//                cout<<"connection is closed"<<endl;
//                break;
//
//
//            } else if (read_bytes < 0) {
//                cout<<"error has occurred"<<endl;
//                break;
//            } else {
//                cout << buffer<<endl;
//            }
//        } else {
//            break;
//        }
//    }
//        close(sock);
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
bool wantToContinue(const string& s){
    return !(s=="-1");
}
bool IsValidK(const string& s){
    for(char i : s){
        if(!isdigit(i))
            return false;
    }
    return true;
}

