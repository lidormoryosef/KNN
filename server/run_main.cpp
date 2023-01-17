
//
// Created by omer on 12/4/22.
//
#include "Tools.h"
# include <string>
#include "ClassifiedArray.h"
#include "Distance.h"
#include <stdexcept>
#include <sstream>
#include "run_main.h"
using namespace std;
/**
 * splitter the string to vector, function distance and k, and send to dedicated functions.
 * @param all , the string we wont to splitter.
 * @param x , this object response to specified the vector.
 * @return if the vector valid return the specified, if invalid return error.
 */
string RunMain::runMain(string all,ClassifiedArray x) {
    stringstream divided(all);
    string line, distance="", k="";
    vector<double> vec;
    while (getline(divided, line, ' ')) {
        try {
            vec.push_back(IsValidDouble(line));
        } catch (invalid_argument &e) {
            distance = line;
            getline(divided, line, ' ');
            k = line;
            break;
        }
    }
    if (getline(divided, line, ' ')||distance.empty()||k.empty()) {
        return "invalid input";
    }
    distances dis=whatDistance(distance);
    if(dis>4)
        return "invalid distance";
    if (!IsValidK(k)) {
        return "invalid k";
    }
    int kNumber;
    try{
        kNumber= stoi(k);
    }catch (exception &e){
        return "invalid k";
    }
    if(kNumber<=0){
        return "invalid k";
        }
    Distance *distance1 = GetDistanceFun(dis);
    x.SetK(kNumber);
    x.SetVectorToCompare(vec);
    x.SetDistance(distance1);
    if(kNumber>x.GetVectors().size())
    {
        return "invalid k";
    }
    try {
        return x.KNN();
    }catch (invalid_argument &e){
        return "invalid vector";
    }

}
