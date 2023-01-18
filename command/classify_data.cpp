//
// Created by lidor on 1/17/23.
//

#include "classify_data.h"

void classify_data::execute() {
    this->data->getClassified().SetK(this->data->getK());
    this->data->getClassified().SetDistance(this->data->getNorm());
    this->data->getClassified().SortByValue();
    int size = this->data->getUnClassified().size();
    for (int i = 0; i <size ; ++i) {
        this->data->getClassified().SetVectorToCompare(this->data->getUnClassified().data()->GetVector());
        this->data->getUnClassified().at(i).SetName(this->data->getClassified().KNN());
    }


}

classify_data::classify_data(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool classify_data::getFlag() {
    return flag;
}

