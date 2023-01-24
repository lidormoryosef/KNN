//
// Created by lidor on 1/17/23.
//

#include "SocketIO.h"

/**
 * receiving massage from the client.
 * @return
 */
string SocketIO::read() {
    ssize_t read_bytes;
    string s,temp;
    while (temp.find('$')==string::npos)
    {
        char buffer[4096] = {0};
        int expected_data_len = sizeof(buffer);
        read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        temp = buffer;
        if (read_bytes == 0) {
            close(client_sock);
            break;
        }
        if (read_bytes < 0) {
            close(client_sock);
            break;
        }
        temp=temp.substr(0, expected_data_len);
        s.append(temp);
    }
    return s.substr(0,s.size()-1);
}
/**
 * constructor.
 * @param client_sock client socket.
 */
SocketIO::SocketIO(int client_sock) {
    this->client_sock=client_sock;
}
/**
 * sending data to client.
 * @param str
 */
void SocketIO::write(string str) {
    string temp;
    str.append("$");
    while (str.size()>4095) {
        temp = str.substr(0,4095);
        str= str.substr(4095);
        int sent_bytes = send(client_sock, &(temp[0]), temp.size(), 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }
    int sent_bytes = send(client_sock, &(str[0]), str.size(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }


}
