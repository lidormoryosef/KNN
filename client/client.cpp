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
#include <thread>
using namespace std;
int checkValidPort (const string& s);
bool wantToContinue(string s);
bool IsValidK(const string& s);
void writeToFile(int sock,string path, string str){
    fstream fin;
    StandardIO local=StandardIO();
    SocketIO dio=SocketIO(sock);
    fin.open(path, ios::out);
    fin << str;
    fin.close();
    dio.write("");
}
/**
 * this function response the connection between the client and the server.
 * @param argc , number of arguments.
 * @param argv  , array of arguments.
 * @return
 */
int main(int argc,char* argv[]) {
    string str;
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
    bool classify = false;
    while (true) {
        DefaultIO *dio=new SocketIO(sock);
        DefaultIO *local=new StandardIO();
        string choice,path,file,temp,params;
        size_t loop=0;
        int pick;
        fstream fin;
        string menu;
        menu = dio->read();
        //dio->write("");
        local->write(menu);
        //dio->write("");
        //dio->read();
        choice=local->read();
        //dio->write("");
        while (choice.empty()){
            local->write("invalid choice, try again.");
            local->write(menu);
            choice=local->read();
        }

        if(IsValidK(choice)){
            pick=stoi(choice);
            dio->write(choice);
            switch(pick) {
                case 1:
                    local->write(dio->read());
                    path = local->read();
                    fin.open(path, ios::in);
                    if (!fin) {
                        cout << "invalid path!" << endl;
                        dio->write("");
                        continue;
                    }
                    while (getline(fin, temp)) {
                        file.append(temp);
                        file.append("\n");
                    }
                    dio->write(file);
                    local->write(dio->read());
                    dio->write("");
                    local->write(dio->read());
                    //dio->write("");
                    fin.close();
                    path = local->read();
                    file.clear();
                    fin.open(path, ios::in);
                    if (!fin) {
                        local->write("invalid path!");
                        dio->write("");
                        continue;
                    }
                    while (getline(fin, temp)) {
                        file.append(temp);
                        file.append("\n");
                    }
                    dio->write(file);
                    local->write(dio->read());
                    fin.close();
                    dio->write("");
                    break;
                case 2:
                    local->write(dio->read());
                    params=local->read();
                    dio->write(params);
                    str = dio->read();
                    if (!str.empty())
                        local->write(str);
                    dio->write("");
                    break;
                case 3:
                    params = dio->read();
                    if (params != "your k is invalid!")
                        classify = true;
                    local->write(params);
                    dio->write("");
                    break;
                case 4:
                    local->write(dio->read());
                    if (classify)
                        local->read();
                    dio->write("");
                    break;
                case 5:
                    if(classify) {
                        path = local->read();
                        str = dio->read();
                        fin.open(path, ios::out);
                        if (!fin) {
                            local->write("invalid path!");
                            break;
                        }
                        fin.close();
                        thread thr(writeToFile,sock,path,str);
                        thr.detach();
                    }else{
                        local->write(dio->read());
                        dio->write("");
                    }

                    break;
                case 8:
                    break;

                default:
                    local->write(dio->read());
                    dio->write("");
                    break;
            }
            if(pick==8){
                close(sock);
                break;
            }
            }else{
            dio->write(choice);
            local->write(dio->read());
            dio->write("");

        }

        }
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

