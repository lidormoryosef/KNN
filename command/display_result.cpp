//
// Created by lidor on 1/17/23.
//

#include "display_result.h"
/**
 * this function execute option 4 in the menu.
 */
void display_result::execute() {
    int size = this->data->getUnClassified().size();
    string message = "";
    for (int i = 0; i <size ; i++) {
        message = message.append(to_string(i+1));
        message = message.append("\t");
        message = message.append(this->data->getUnClassified().at(i).GetName());
        message = message.append("\n");
    }
    message = message.append("Done.\n");
    dio->write(message);
    dio->read();
}
/**
 * constructor.
 * @param des, the description of class.
 * @param dio , object that responsible the communication between the server and the client.
 * @param data , the data of program.
 */
display_result::display_result(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}
/**
 * getter.
 * @return this flag response for program integrity
 */
bool display_result::getFlag() {
    return flag;
}
