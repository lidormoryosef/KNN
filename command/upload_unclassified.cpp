//
// Created by lidor on 1/17/23.
//

#include "upload_unclassified.h"

#include <utility>

void upload_unclassified::execute() {

}

upload_unclassified::upload_unclassified(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;
}

bool upload_unclassified::getFlag() {
    return flag;
}
