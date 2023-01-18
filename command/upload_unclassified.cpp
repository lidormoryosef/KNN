//
// Created by lidor on 1/17/23.
//

#include "upload_unclassified.h"
#include "../IO/DefaultIO.h"
#import <sstream>
#include <utility>
#include "../server/Tools.h"
void upload_unclassified::execute() {
    dio->write("Please upload your local train CSV file.");
    vector<NameVector> vectorWithoutClassification;
    ClassifiedArray vectorWithClassification;
    vectorWithClassification=populateTheClassified();
    if(!flag)
        return;
    dio->write("Upload complete.");
    dio->write("Please upload your local test CSV file.");
    vectorWithoutClassification=populateTheUnClassified();
    if(!flag)
        return;
    this->data->setClassified(vectorWithClassification);
    this->data->setUnClassified(vectorWithoutClassification);
    dio->write("Upload complete.");
}

upload_unclassified::upload_unclassified(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data=data;
}

bool upload_unclassified::getFlag() {
    return flag;
}

ClassifiedArray upload_unclassified::populateTheClassified() {
    string str=dio->read();
    ClassifiedArray array=ClassifiedArray();
    int len=str.size()-1;
    string last=str.substr(0,len-1);
    array.setVectors(PopulateVectorClassified(last));
    return array;
}

vector<NameVector> upload_unclassified::populateTheUnClassified() {
    string str=dio->read();
    ClassifiedArray array=ClassifiedArray();
    int len=str.size()-1;
    string last=str.substr(0,len-1);
    array.setVectors(PopulateVectorUnClassified(last));
    return array.GetVectors();
}
vector<NameVector> upload_unclassified::PopulateVectorClassified(const string& line)  {
    string temp,curr;
    vector<NameVector> vectors;
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
                        dio->write("the vectors arent in the same size");
                        flag=false;
                    }

                }
            }
        }

    }
    flag=true;
    return vectors;
}

vector<NameVector> upload_unclassified::PopulateVectorUnClassified(const string& line)  {
    string temp,curr;
    vector<NameVector> vectors;
    stringstream dev(line);
    while(getline(dev,curr,'\n')) {
        stringstream s(curr);
        vector<double> vec;
        while (getline(s, temp, ',')) {
            try {
                vec.push_back(IsValidDouble(temp));
            }catch (invalid_argument &e) {
                dio->write("the vectors are invalid");
                flag=false;
                return vectors;
            }
        }
            NameVector v = NameVector("", vec);
            if (vectors.empty()) {
                if (!ValidVectors(data->getClassified().GetVectors().at(0).GetVector(), vec)) {
                    dio->write("the vectors arent in the same size");
                    flag=false;
                    return vectors;
                }
                vectors.push_back(v);
            } else {
                if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                    vectors.push_back(v);
                } else {
                    dio->write("the vectors arent in the same size");
                    flag=false;
                    return vectors;
                }
            }
        }
    flag=true;
    return vectors;
    }
