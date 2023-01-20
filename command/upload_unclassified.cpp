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
    dio->read();
    this->data->setClassified(vectorWithClassification);
    dio->write("Please upload your local test CSV file.");
    vectorWithoutClassification=populateTheUnClassified();
    if(!flag) {
        data->setClassified(temp);
        return;
    }
    this->data->setUnClassified(vectorWithoutClassification);
    dio->write("Upload complete.");
    dio->read();
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
vector<NameVector> upload_unclassified::PopulateVectorClassified(string& line)  {
    string temp,curr;
    vector<NameVector> vectors;
    size_t index;
    size_t delim1, delim2;
    while((delim1 = line.find('\n')) != string::npos) {
        string l = line.substr(0, delim1);
        line = line.substr(delim1 + 1);
        vector<double> vec;
        while ((delim2 = l.find(',')) != string::npos) {
            temp = l.substr(0, delim2);
            l = l.substr(delim2 + 1);
            try {
                double number=stod(temp,&index);
                if (index < temp.size()) {
                    throw invalid_argument("error");
                }
                vec.push_back(number);
            } catch (invalid_argument &e) {
                dio->write("invalid input");
            }
        }
        NameVector v(l.substr(delim2 + 1), vec);
        if (vectors.empty()) {
            vectors.push_back(v);
        } else {
            if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                vectors.push_back(v);
            } else {
                dio->write("invalid input");
                flag=false;
                return vectors;
            }
        }
    }
    flag=true;
    return vectors;
}

vector<NameVector> upload_unclassified::PopulateVectorUnClassified(string& line)  {
    string temp,curr;
    vector<NameVector> vectors;
    size_t index;
    size_t delim1, delim2;
    while((delim1 = line.find('\r')) != string::npos) {
        string l = line.substr(0, delim1);
        line = line.substr(delim1 + 1);
        vector<double> vec;
        while ((delim2 = l.find(',')) != string::npos) {
            temp = l.substr(0, delim2);
            l = l.substr(delim2 + 1);
            try {
                double number=stod(temp,&index);
                if (index < temp.size()) {
                    dio->write("invalid input");
                }
                vec.push_back(number);
            } catch (invalid_argument &e) {
                dio->write("invalid input");
            }
        }
        vec.push_back(stod(line));
        NameVector v("", vec);
        if (vectors.empty()) {
            vectors.push_back(v);
        } else {
            if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                vectors.push_back(v);
            } else {
                dio->write("invalid input");
                flag=false;
                return vectors;
            }
        }
    }
    flag=true;
    return vectors;

//    string temp,curr;
//    vector<NameVector> vectors;
//    stringstream dev(line);
//    while(getline(dev,curr,'\n')) {
//        stringstream s(curr);
//        vector<double> vec;
//        while (getline(s, temp, ',')) {
//            try {
//                vec.push_back(IsValidDouble(temp));
//            }catch (invalid_argument &e) {
//                dio->write("the vectors are invalid");
//                flag=false;
//                return vectors;
//            }
//        }
//            NameVector v = NameVector("", vec);
//            if (vectors.empty()) {
//                if (!ValidVectors(data->getClassified().GetVectors().at(0).GetVector(), vec)) {
//                    dio->write("the vectors arent in the same size");
//                    flag=false;
//                    return vectors;
//                }
//                vectors.push_back(v);
//            } else {
//                if (ValidVectors(vectors.at(0).GetVector(), vec)) {
//                    vectors.push_back(v);
//                } else {
//                    dio->write("the vectors arent in the same size");
//                    flag=false;
//                    return vectors;
//                }
//            }
//        }
//    flag=true;
//    return vectors;
    }
