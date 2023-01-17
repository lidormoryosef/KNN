//
// Created by lidor on 1/17/23.
//

#include "exit_command.h"

void exit_command::execute() {

}

exit_command::exit_command(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;

}

bool exit_command::getFlag() {
    return flag;
}
