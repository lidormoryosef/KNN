//
// Created by omer on 12/4/22.
//

#ifndef EX2_DISTANCE_H
#define EX2_DISTANCE_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
using namespace std;
/**
 * abstract class that all the distances inheritance.
 */
class Distance {
public:
    virtual double distance(vector<double> v1, vector<double> v2)=0;
};


#endif //EX2_DISTANCE_H
