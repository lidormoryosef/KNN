//
// Created by lidor on 1/17/23.
//

#include "download_results.h"

void download_results::execute() {

}
download_results::download_results(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;
}

bool download_results::getFlag() {
    return flag;
}
