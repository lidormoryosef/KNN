//
// Created by omer on 12/4/22.
//

#ifndef EX2_MINKOWSKIDISTANCE_H
#define EX2_MINKOWSKIDISTANCE_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#define P 2
#include "Distance.h"
using namespace std;
/**
 * this class represent minkowski distance.
 */
class MinkowskiDistance:public Distance  {
    double distance (vector<double> v1 , vector<double> v2) override;
};


#endif //EX2_MINKOWSKIDISTANCE_H
