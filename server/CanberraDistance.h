//
// Created by omer on 12/4/22.
//

#ifndef EX2_CANBERRADISTANCE_H
#define EX2_CANBERRADISTANCE_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
using namespace std;
/**
 * this class represent canberra distance.
 */
class CanberraDistance: public Distance {
    double distance(vector<double> v1,vector<double> v2) override;

};

#endif //EX2_CANBERRADISTANCE_H
