//
// Created by omer on 1/18/23.
//

#ifndef EX_4_GLOBAL_DATA_H
#define EX_4_GLOBAL_DATA_H


#include "server/ClassifiedArray.h"
#include "server/EuclideanDistance.h"

class global_data {
private:
    int k;
    ClassifiedArray classifiedArray;
    vector<NameVector> unClassifiedArray;
    Distance* norm;
    string name_norm;
public:
    void setClassified(ClassifiedArray classified);
    void setUnClassified(vector<NameVector> unClassified);
    void setK(int k);
    void setNorm(Distance* dis);
    void setNameNorm(string name);
    ClassifiedArray getClassified();
    vector<NameVector> getUnClassified();
    int getK() const;
    Distance* getNorm();
    string getNameNorm();
    global_data();
};


#endif //EX_4_GLOBAL_DATA_H
