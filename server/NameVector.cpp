//
// Created by omer on 12/4/22.
//
#include "NameVector.h"

#include <utility>
/**
 * getter
 * @return name of data.
 */
string NameVector::GetName() {return name;}
/**
 * setter.
 * @param name1 the new data name.
 */
void NameVector::SetName(string name1) {name = std::move(name1);}
/**
 * setter.
 * @param vector1 new classified vector
 */
void NameVector::SetVector(const ::vector<double>& vector1) { vector = vector1;}
/**
 * getter.
 * @return vector
 */
vector<double> NameVector::GetVector() { return this->vector;}
/**
 * contractor.
 * @param name name of data.
 * @param vector classified vector..
 */
NameVector::NameVector(string name, ::vector<double> vector) {
    this->name=std::move(name);
    this->vector=std::move(vector);
}
/**
 * setter.
 * @param distance between me and the data we wont to classified.
 */
void NameVector::SetDistanceFromVector(double distance) {
    this->DistanceFromVector=distance;
}
/**
 * getter.
 * @return distance from vector.
 */
double NameVector::GetDistanceFromVector() {
    return this->DistanceFromVector;

}
