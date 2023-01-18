//
// Created by omer on 12/4/22.
//

#ifndef EX2_CLASSIFIEDARRAY_H
#define EX2_CLASSIFIEDARRAY_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
#include "NameVector.h"
#include <algorithm>
#include <map>
using namespace std;
/**
 * responsibly to KNN.
 */
class ClassifiedArray {
private:
    vector<NameVector> vectors;
    Distance *distance;
    string path;
    vector<double> ToCompare;
    int k;

public:
    ClassifiedArray(string path, vector<double> ToCompare, int k, Distance *distance1);
    ClassifiedArray();
    void PopulateVector();
    std::vector<NameVector> GetVectors();
    void setVectors(vector<NameVector> arr);
    string GetPath();
    void SetPath (string NewPath);
    void SetVectorToCompare (const vector<double>& vector);

    int GetK() const;
    void SetK (int k);
    void SetDistance(Distance *distance1);

    void SortByValue();
    void PopulateDistance ();
    string FindClassification();

    string KNN ();

};


#endif //EX2_CLASSIFIEDARRAY_H
