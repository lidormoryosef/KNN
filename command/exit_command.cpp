//
// Created by lidor on 1/17/23.
//

#include "exit_command.h"

void exit_command::execute() {
    free(data->getNorm());
    free(dio);
    free(data);
}

exit_command::exit_command(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool exit_command::getFlag() {
    return flag;
}
