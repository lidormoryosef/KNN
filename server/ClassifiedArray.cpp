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
        exit_command(0);
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
                        exit_command(0);
                    }

                }
            }
        }

    }
    fin.close();
}
/**
 * This function check which type data appears most times in first k vectors on data base ofter sort.
 * @return , type of data the appears most times.
 */
string ClassifiedArray::FindClassification(){
    map<string,int> map;
    for(int i=0;i<this->k;i++){
        if(map.count(this->vectors.at(i).GetName())){
            map.at(this->vectors.at(i).GetName())++;
        }else{
            map.insert({this->vectors.at(i).GetName(),1});
        }
    }
    string curr;
    int max=0;
    for(auto & it : map){
        if(max<it.second) {
            curr = it.first;
            max=it.second;
        }
    }
    return curr;
}
/**
 * compare function for sort.
 * @param v1 , first vector we wont to compare.
 * @param v2 , secund vector we wont to compare.
 * @return if the first smallest than first.
 */
bool CompareDistance(NameVector v1,NameVector v2){
    return v1.GetDistanceFromVector()<v2.GetDistanceFromVector();
}
/**
 * this function sort the data base by ascending order the distance between vector to vector we wont to classified.
 */
void ClassifiedArray::SortByValue(){
    sort(vectors.begin(),vectors.end(), CompareDistance);
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
void ClassifiedArray::PopulateDistance() {
    if(ValidVectors(this->ToCompare,this->vectors.at(0).GetVector())) {
        for (int i = 0; i < this->vectors.size(); ++i) {
            vectors.at(i).SetDistanceFromVector(distance->distance(ToCompare, vectors.at(i).GetVector()));
        }
    }
    else{
        string message="the vector is invalid";
        throw invalid_argument(message);

    }

}

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
 * run the all project.
 * @return the vector we classified.
 */
string ClassifiedArray::KNN() {
    PopulateDistance();
    SortByValue();
    return FindClassification();

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
void ClassifiedArray::PopulateVector1(string line) {
    string temp,curr;
    stringstream dev(line);
    while(getline(dev,curr,'\n')) {
        stringstream s(curr);
        vector<double> vec;
        while (getline(s, temp, ',')) {
            try {
                vec.push_back(IsValidDouble(temp));
            } catch (invalid_argument &e) {
                NameVector v = NameVector(temp, vec);
                if (vectors.empty()) {
                    vectors.push_back(v);
                } else {
                    if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                        vectors.push_back(v);
                    } else {
                        cout << "the vectors arent in the same size" << endl;
                        exit_command(0);
                    }

                }
            }
        }
    }

}
void ClassifiedArray::PopulateVector2(string line){
    string temp,curr;
    stringstream dev(line);
    while(getline(dev,curr,'\n')) {
        stringstream s(curr);
        vector<double> vec;
        while (getline(s, temp, ',')) {
            try {
                vec.push_back(IsValidDouble(temp));
            } catch (invalid_argument &e) {
                NameVector v = NameVector("", vec);
                if (vectors.empty()) {
                    vectors.push_back(v);
                } else {
                    if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                        vectors.push_back(v);
                    } else {
                        cout << "the vectors arent in the same size" << endl;
                        exit_command(0);
                    }

                }
            }
        }
    }
}
