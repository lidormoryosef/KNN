//
// Created by omer on 12/4/22.
//

#include "ManhattanDistance.h"
/**
 * calculates the manhattan distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the manhattan distance between the two vectors.
 */
double ManhattanDistance::distance(vector<double> v1,vector<double> v2){
    double sum=0;
    for(int i=0;i<v1.size();i++){
        sum+= abs(v1.at(i)-v2.at(i));
    }
    return sum;
}