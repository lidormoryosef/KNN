//
// Created by omer on 12/4/22.
//

#ifndef EX2_CHEBYSHEV_H
#define EX2_CHEBYSHEV_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
using namespace std;
/**
 * this class represent chebyshev distance.
 */
class ChebyshevDistance:public Distance  {
    double distance(vector<double> v1,vector<double> v2) override;

};


#endif //EX2_CHEBYSHEV_H
