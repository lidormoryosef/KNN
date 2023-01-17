//
// Created by lidor on 1/17/23.
//

#include <iostream>
#include "StandardIO.h"

string StandardIO::read() {
    string input;
    getline(cin, input);
    return input;
}

void StandardIO::write(string str) {
     cout<<str<<endl;
}
