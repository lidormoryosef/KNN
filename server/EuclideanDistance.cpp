//
// Created by omer on 12/4/22.
//

#include "EuclideanDistance.h"
/**
 * calculates the euclidean distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the euclidean distance between the two vectors.
 */
double EuclideanDistance::distance(vector<double> v1,vector<double> v2){
    double sum=0;
    for(int i=0;i<v1.size();i++){
        sum+= pow(v1.at(i)-v2.at(i),2);
    }
    return sqrt(sum);
}