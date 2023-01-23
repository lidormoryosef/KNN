//
// Created by omer on 1/18/23.
//

#include "global_data.h"

#include <utility>
/**
 * setter.
 * @param classified , train file.
 */
void global_data::setClassified(ClassifiedArray classified) {
    this->classifiedArray = std::move(classified);
}
/**
 * setter.
 * @param unClassified , the file we want to classified.
 */
void global_data::setUnClassified(vector<NameVector> unClassified) {
    this->unClassifiedArray=std::move(unClassified);

}
/**
 * setter
 * @param k precision.
 */
void global_data::setK(int k) {
    this->k=k;

}
/**
 * setter.
 * @param dis distance metric.
 */
void global_data::setNorm(Distance *dis) {
    this->norm = dis;
}
/**
 * setter.
 * @param name of vector.
 */
void global_data::setNameNorm(string name) {
    this->name_norm=std::move(name);

}
/**
 * getter.
 * @return train file.
 */
ClassifiedArray global_data::getClassified() {
    return this->classifiedArray;
}
/**
 * getter.
 * @return classified file.
 */
vector<NameVector> global_data::getUnClassified() {
    return this->unClassifiedArray;
}
/**
 * getter.
 * @return precision.
 */
int global_data::getK() const {
    return this->k;
}
/**
 * getter.
 * @return  name of distance metric.
 */
string global_data::getNameNorm() {
    return this->name_norm;
}
/**
 * distance metric.
 * @return
 */
Distance *global_data::getNorm() {
    return this->norm;
}
/**
 * initializes the metric and k to default values.
 */
global_data::global_data() {
    this->k = 5;
    this->norm = new EuclideanDistance;
    this->name_norm = "EUC";
}

