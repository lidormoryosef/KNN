//
// Created by omer on 12/4/22.
//

#ifndef EX2_EUCLIDEANDISTANCE_H
#define EX2_EUCLIDEANDISTANCE_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
using namespace std;
/**
 * this class represent euclidean distance.
 */
class EuclideanDistance:public Distance  {
    double distance(vector<double> v1,vector<double> v2) override;
};


#endif //EX2_EUCLIDEANDISTANCE_H
