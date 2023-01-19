//
// Created by omer on 12/4/22.
//

#include "ClassifiedArray.h"
#include <utility>
# include <vector>
# include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "Tools.h"

/**
 * constructor.
 * @param path , the path of file.
 * @param ToCompare  , the vector that we wont to compare.
 * @param k, how macy nearest to neighbors ww wont.
 * @param distance1 , the distance we wont to calculate.
 */
ClassifiedArray::ClassifiedArray(string path , vector<double> ToCompare, int k, Distance *distance1) {
    this->path=std::move(path);
    this->ToCompare = std::move(ToCompare);
    this->k = k;
    this->distance = distance1;
}
/**
 * constructor
 * @param path ,the path of file.
 */
ClassifiedArray::ClassifiedArray(){
}
/**
 * this function get from file the vectors that represent data and insert him to new data base.
 */
void ClassifiedArray::PopulateVector() {
    fstream fin;
    fin.open(this->path,ios::in);
    if(!fin){
        cout<<"invalid path!"<<endl;
        exit(0);
    }
    string line,temp;
    while(getline(fin,temp)){
        stringstream s(temp);
        vector<double> vec;
        while(getline(s,line,',')){
            try{
                vec.push_back(IsValidDouble(line));
            }catch(invalid_argument &e){
                NameVector v=NameVector(line,vec);
                if(vectors.empty()) {
                    vectors.push_back(v);
                }
                else{
                    if(ValidVectors(vectors.at(0).GetVector(),vec)) {
                        vectors.push_back(v);
                    }
                    else{
                        cout<<"the vectors arent in the same size"<<endl;
                        exit(0);
                    }

                }
            }
        }

    }
    fin.close();
}
/**
 * getter.
 * @return the data base.
 */
vector<NameVector> ClassifiedArray::GetVectors(){
    return vectors;
}
/**
 * getter.
 * @return the pate of file we wont to read.
 */
string ClassifiedArray::GetPath() {
    return path;
}
/**
 * setter.
 * @param NewPath new path that we wont to update.
 */
void ClassifiedArray::SetPath (string NewPath){
    path=std::move(NewPath);
}
/**
 * This function update the field of distance in ant data in data base to the distance between him to vector compare.
 */

/**
 * getter.
 * @return the number of nearest to neighbors we wont.
 */
int ClassifiedArray::GetK() const {
    return this->k;
}
/**
 * setter.
 * @param k   number of nearest to neighbors we wont.
 */
void ClassifiedArray::SetK(int k) {
    this->k = k;
}
/**
 * setter.
 * @param ToCompare set the vector  .
 */
void ClassifiedArray::SetVectorToCompare(const vector<double>& vector) {
    this->ToCompare=vector;
}
/**
 * setter.
 * @param distance1 , the distance we wont to calculate.
 */
void ClassifiedArray::SetDistance(Distance *distance1) {
    this->distance=distance1;
}

void ClassifiedArray::setVectors(vector<NameVector> arr) {
    this->vectors=std::move(arr);
}

