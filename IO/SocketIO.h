//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_SOCKETIO_H
#define EX_4_SOCKETIO_H

#include <iostream>
#include "DefaultIO.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/**
 * responsible for the interface between the client and the server by socket.
 */
class SocketIO: public DefaultIO{
private:
    int client_sock;
public:
    SocketIO(int client_sock);
    string read() override;
    void write (string str) override;
};


#endif //EX_4_SOCKETIO_H
