//
// Created by omer on 12/4/22.
//

#include "CanberraDistance.h"

/**
 * This function calculate the distance between two vector by canberra.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the distance.
 */
double CanberraDistance::distance(vector<double> v1, vector<double> v2) {
    double distance, sum = 0, AbsV1, AbsV2;
    for (int i = 0; i < v1.size(); ++i) {
        distance = abs(v1.at(i)-v2.at(i));
        AbsV1 = abs(v1.at(i));
        AbsV2 = abs(v2.at(i));
        if (AbsV1 == 0 && AbsV2 == 0)
            continue;
        sum += distance/(AbsV1 + AbsV2);
    }
    return sum;
}