//
// Created by lidor on 12/6/22.
//
#include <vector>
using namespace std;
#include <string>
#include <iostream>
#include <stdexcept>
#include "Distance.h"
#include "ManhattanDistance.h"
#include "MinkowskiDistance.h"
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "EuclideanDistance.h"
#include "Tools.h"
#include <sstream>
/**
 * check if the port are valid.
 * @param s , string of port.
 * @return , if valid return the integer port , if not return -1.
 */
int checkValidPort (const string& s){
    for(char i : s){
        if(!isdigit(i))
            return -1;
    }
    int port=stoi(s);
    if(port<65536)
        return port;
    return -1;
}
/**
 * this function represent any distance to enum.
 * @param dis
 * @return the distance wanted, or error.
 */
distances whatDistance (const string& dis){
    if (dis == "AUC") {return AUC;}
    if (dis == "MAN") {return MAN;}
    if (dis == "CHB") {return CHB;}
    if (dis == "CAN") {return CAN;}
    if (dis == "MIN") {return MIN;}
    return ERROR;
}
/**
 * the function receives a string and checks weather it can be modified into a double character.
 * @param s the string.
 * @return if the string ia number, return the number, else throw exception.
 */
double IsValidDouble(const string& s){
    string message="the vector is invalid";
    size_t index;
    double number=stod(s,&index);
    if(index<s.size()){
        throw invalid_argument(message);
    }
    return number;
}

/**
 * check if the vector is same size.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return true or false.
 */
bool ValidVectors (const vector<double>& v1 ,const vector<double>& v2){
    return v1.size() == v2.size()&&!v1.empty();
}
/**
 * the function receives from the the user input, and devices it to doubles(if legal) and
 * spaces ,and each space indicates that we move to the next component.
 * @return the fully populated vector.
 */
vector<double> MakeVector () {
    double number;
    string s,num;
    vector<double> v;
    string message="the vector is invalid";
    getline(cin,s);
    stringstream temp(s);
    while(getline(temp,num,' ')){
        if(num.empty())
            throw invalid_argument(message);
        try{
            number= IsValidDouble(num);
        }catch(invalid_argument &e){
            //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument(message);
        }
        v.push_back(number);
    }
    return v;
    }

/**
 * this function return a reference.
 * @param dis enum that represent type of distance.
 * @return reference of class distance.
 */
Distance* GetDistanceFun(distances dis) {
    switch (dis) {
        case AUC:
            return new EuclideanDistance;
        case MAN:
            return new ManhattanDistance;
        case CHB:
            return new ChebyshevDistance;
        case CAN:
            return new CanberraDistance;
        case MIN:
            return new MinkowskiDistance;

    }
    return nullptr;
}
/**
 * check if k is number.
 * @param s , the string we wont to check.
 * @return
 */
bool IsValidK(const string& s){
    for(char i : s){
        if(!isdigit(i))
            return false;
    }
    return true;
}