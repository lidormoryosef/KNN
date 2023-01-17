//
// Created by omer on 12/4/22.
//

#include "MinkowskiDistance.h"
/**
 * This function calculate the distance between two vector by minkowski.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @param p the default p that with it we calculate the distance.
 * @return the distance.
 */
double MinkowskiDistance::distance (vector<double> v1 , vector<double> v2){
    double sum=0, distance, result;
    for (int i = 0; i < v1.size(); ++i) {
        distance = abs(v1.at(i)-v2.at(i));
        sum += pow(distance,P);
    }
    result = pow(sum,(1/P));
    return result;

}