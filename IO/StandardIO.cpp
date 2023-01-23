//
// Created by lidor on 1/17/23.
//

#include <iostream>
#include "StandardIO.h"
/**
 * receiving massage from the client.
 * @return
 */
string StandardIO::read() {
    string input;
    getline(cin, input);
    return input;
}
/**
 * sending data to client.
 * @param str
 */
void StandardIO::write(string str) {
     cout<<str<<endl;
}
