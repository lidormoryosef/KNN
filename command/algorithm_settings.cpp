//
// Created by lidor on 1/17/23.
//

#include "algorithm_settings.h"

void algorithm_settings::execute() {

}

algorithm_settings::algorithm_settings(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;

}

bool algorithm_settings::getFlag() {
    return flag;
}
