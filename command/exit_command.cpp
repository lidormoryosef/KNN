//
// Created by lidor on 1/17/23.
//

#include "exit_command.h"
/**
 * this function execute option 8 in the menu.
 */
void exit_command::execute() {
    free(data->getNorm());
    free(dio);
    free(data);
}
/**
 * constructor.
 * @param des, the description of class.
 * @param dio , object that responsible the communication between the server and the client.
 * @param data , the data of program.
 */
exit_command::exit_command(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}
/**
 * getter.
 * @return this flag response for program integrity
 */
bool exit_command::getFlag() {
    return flag;
}
