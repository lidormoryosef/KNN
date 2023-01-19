//
// Created by lidor on 1/17/23.
//

#include "display_result.h"

void display_result::execute() {
    int size = this->data->getUnClassified().size();
    for (int i = 0; i <size ; ++i) {
        string message = "";
        message = message.append(to_string(i+1));
        message = message.append("\t");
        message = message.append(this->data->getUnClassified().at(i).GetName());
        message = message.append("\n");
        dio->write(message);
    }
    dio->write("Done.\n");
    //dio->read();
}

display_result::display_result(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool display_result::getFlag() {
    return flag;
}
