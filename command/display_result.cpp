//
// Created by lidor on 1/17/23.
//

#include "display_result.h"

void display_result::execute() {

}

display_result::display_result(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;

}

bool display_result::getFlag() {
    return flag;
}
