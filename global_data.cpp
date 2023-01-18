//
// Created by omer on 1/18/23.
//

#include "global_data.h"

#include <utility>

void global_data::setClassified(ClassifiedArray classified) {
    this->classifiedArray = std::move(classified);
}

void global_data::setUnClassified(vector<NameVector> unClassified) {
    this->unClassifiedArray=std::move(unClassified);

}

void global_data::setK(int k) {
    this->k=k;

}

void global_data::setNorm(Distance *dis) {
    this->norm = dis;
}

void global_data::setNameNorm(string name) {
    this->name_norm=std::move(name);

}

ClassifiedArray global_data::getClassified() {
    return this->classifiedArray;
}

vector<NameVector> global_data::getUnClassified() {
    return this->unClassifiedArray;
}

int global_data::getK() const {
    return this->k;
}

string global_data::getNameNorm() {
    return this->name_norm;
}

Distance *global_data::getNorm() {
    this->norm;
}

global_data::global_data() {
    this->k = 5;
    this->norm = new EuclideanDistance;
    this->name_norm = "EUC";
}

