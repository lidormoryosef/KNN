//
// Created by lidor on 1/17/23.
//

#include <iostream>
#include "SocketIO.h"

string SocketIO::read() {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes;
    string s;
    do {
        read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            close(client_sock);
            break;
        }
            if (read_bytes < 0) {
            close(client_sock);
            break;
        }
        s=s.append(buffer);

    } while (buffer[read_bytes-1]!='$');
    return s.substr(0,s.size()-1);
}
SocketIO::SocketIO(int client_sock) {
    this->client_sock=client_sock;
}

void SocketIO::write(string str) {
    str.append("$");
    const char* toSend=str.c_str();
    int sent_bytes = send(client_sock,toSend, str.size(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

}
