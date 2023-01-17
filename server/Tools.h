//
// Created by lidor on 12/6/22.
//

#ifndef EX2_TOOLS_H
#define EX2_TOOLS_H
#include "Distance.h"
#include<vector>
#include <string>

using namespace std;
/**
 * this class contains auxiliary function.
 */
enum distances {
    AUC,
    MAN,
    CHB,
    CAN,
    MIN,
    ERROR
};
int checkValidPort (const string& s);
bool IsValidK(const string& s);
distances whatDistance (const string& dis);
double IsValidDouble(const string& s);
bool ValidVectors (const vector<double>& v1 ,const vector<double>& v2);
vector<double> MakeVector ();
Distance* GetDistanceFun(distances dis);



#endif //EX2_TOOLS_H
