//
// Created by omer on 12/4/22.
//

#include "ChebyshevDistance.h"
/**
 * calculates the chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the chebyshev distance between the two vectors.
 */
double ChebyshevDistance::distance(vector<double> v1,vector<double> v2){
    double max=0;
    for(int i=0;i<v1.size();i++){
        double cur=abs(v1.at(i)-v2.at(i));
        if(max<cur)
            max=cur;
    }
    return max;
}