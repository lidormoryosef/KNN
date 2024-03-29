//
// Created by lidor on 1/17/23.
//
#include "classify_data.h"

#include <utility>
/**
 * this function execute option 3 in the menu.
 */
void classify_data::execute() {
    int size = this->data->getClassified().GetVectors().size();
    if (size< this->data->getK()) {
        dio->write("your k is invalid!");
        dio->read();
        return;
    }

    vector<NameVector> temp=this->data->getUnClassified();
    size = this->data->getUnClassified().size();
    for (int i = 0; i <size ; ++i) {
        vector<double> vv = this->data->getUnClassified().at(i).GetVector();
        try {
            string s = KNN(vv);
            temp.at(i).SetName(s);
        }catch(invalid_argument &e) {
            dio->write("the vector is invalid");
            dio->read();
            return;
        }
    }
    this->data->setUnClassified(temp);
    this->flag= true;
    this->dio->write("classifying data complete");
    dio->read();
}
classify_data::classify_data(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool classify_data::getFlag() {
    return flag;
}
/**
 * this function get from file the vectors that represent data and insert him to new data base.
 */
void classify_data::PopulateDistance(const vector<double>& compare) {
    ClassifiedArray temp=this->data->getClassified();
    vector<NameVector> v=temp.GetVectors();
    int size = this->data->getClassified().GetVectors().size();
    vector<NameVector> vectors = this->data->getClassified().GetVectors();
    Distance *norm =  this->data->getNorm();
    if(ValidVectors(compare, this->data->getClassified().GetVectors().at(0).GetVector())) {
        for (int i = 0; i < size; ++i) {
            double dis = norm->distance(vectors.at(i).GetVector(),compare);
            v.at(i).SetDistanceFromVector(dis);
        }
    }
    else{
        string message="the vector is invalid";
        throw invalid_argument(message);

    }
    temp.setVectors(v);
    this->data->setClassified(temp);
}
/**
 * run the all project.
 * @return the vector we classified.
 */
string classify_data::KNN(const vector<double>& compare) {
    PopulateDistance(compare);
    if (this->data->getClassified().GetVectors().size()>1)
        SortByValue();
    return FindClassification();
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
void classify_data::SortByValue() {
    ClassifiedArray cls;
    vector<NameVector> v = this->data->getClassified().GetVectors();
    sort(v.begin(), v.end(),CompareDistance);
    cls.setVectors(v);
    this->data->setClassified(cls);
}
/**
 * This function check which type data appears most times in first k vectors on data base ofter sort.
 * @return , type of data the appears most times.
 */
string classify_data::FindClassification() {
    map<string,int> map;
    for(int i=0;i<this->data->getK();i++){
        if(map.count(this->data->getClassified().GetVectors().at(i).GetName())){
            map.at(this->data->getClassified().GetVectors().at(i).GetName())++;
        }else{
            map.insert({this->data->getClassified().GetVectors().at(i).GetName(),1});
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

