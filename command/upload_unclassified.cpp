//
// Created by lidor on 1/17/23.
//
#include "upload_unclassified.h"
void upload_unclassified::execute() {
    dio->write("Please upload your local train CSV file.");
    //dio->read();
    vector<NameVector> vectorWithoutClassification;
    ClassifiedArray vectorWithClassification;
    ClassifiedArray temp=data->getClassified();
    vectorWithClassification=populateTheClassified();
    if(!flag)
        return;
    dio->write("Upload complete.");
    this->data->setClassified(vectorWithClassification);
    dio->write("Please upload your local test CSV file.");
    vectorWithoutClassification=populateTheUnClassified();
    if(!flag) {
        data->setClassified(temp);
        return;
    }
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
    array.setVectors(PopulateVectorClassified(str));
    return array;
}

vector<NameVector> upload_unclassified::populateTheUnClassified() {
    string str=dio->read();
    ClassifiedArray array=ClassifiedArray();
    array.setVectors(PopulateVectorUnClassified(str));
    return array.GetVectors();
}
vector<NameVector> upload_unclassified::PopulateVectorClassified(const string& line)  {
    string temp,curr;
    vector<NameVector> vectors;
    stringstream dev(line);
    size_t index;
    while(getline(dev,curr,'\n')) {
        stringstream s(curr);
        vector<double> vec;
        while (getline(s, temp, ',')) {
            try {
                double number=stod(temp,&index);
                if (index < temp.size()) {
                    throw invalid_argument("error");
                }
                vec.push_back(number);
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
                        return vectors;
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
