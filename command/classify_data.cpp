//
// Created by lidor on 1/17/23.
//

#include "classify_data.h"

void classify_data::execute() {

}

classify_data::classify_data(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;
}

bool classify_data::getFlag() {
    return flag;
}

