//
// Created by omer on 12/4/22.
//

#ifndef EX2_MANHATTAN_H
#define EX2_MANHATTAN_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
using namespace std;
/**
 * this class represent Manhattan distance.
 */
class ManhattanDistance:public Distance  {
    double distance(vector<double> v1, vector<double> v2) override;

};


#endif //EX2_MANHATTAN_H
