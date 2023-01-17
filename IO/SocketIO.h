//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_SOCKETIO_H
#define EX_4_SOCKETIO_H


#include "DefaultIO.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <csignal>

class SocketIO: public DefaultIO{
private:
    int client_sock;
public:
    SocketIO(int client_sock);
    string read() override;
    void write (string str) override;
};


#endif //EX_4_SOCKETIO_H
