//
// Created by lidor on 1/17/23.
//

#include "download_results.h"

void download_results::execute() {
    int size = this->data->getUnClassified().size();
    for (int i = 0; i <size ; ++i) {
        string message = "";
        message = message.append(to_string(i+1));
        message = message.append("\t");
        message = message.append(this->data->getUnClassified().data()->GetName());
        message = message.append("\n");
        dio->write(message);
    }
}
download_results::download_results(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data=data;
}

bool download_results::getFlag() {
    return flag;
}
