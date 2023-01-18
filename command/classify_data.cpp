//
// Created by lidor on 1/17/23.
//

#include "classify_data.h"

void classify_data::execute() {

}

classify_data::classify_data(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool classify_data::getFlag() {
    return flag;
}

