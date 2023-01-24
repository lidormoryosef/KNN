//
// Created by lidor on 1/17/23.
//
#include "upload_unclassified.h"
/**
 * this function execute option 1 in the menu.
 */
void upload_unclassified::execute() {
    dio->write("Please upload your local train CSV file.");
    //dio->read();
    vector<NameVector> vectorWithoutClassification;
    ClassifiedArray vectorWithClassification;
    ClassifiedArray temp=data->getClassified();
    string str=dio->read();
    if (str.empty())
        return ;
    vectorWithClassification=populateTheClassified(str);
    if(!flag)
        return;
    dio->write("Upload complete.");
    dio->read();
    this->data->setClassified(vectorWithClassification);
    dio->write("Please upload your local test CSV file.");
    str=dio->read();
    if (str.empty()) {
        this->flag= false;
        return;
    }
    vectorWithoutClassification=populateTheUnClassified(str);
    if(!flag) {
        data->setClassified(temp);
        return;
    }
    this->data->setUnClassified(vectorWithoutClassification);
    dio->write("Upload complete.");
    dio->read();
}
/**
 * constructor.
 * @param des, the description of class.
 * @param dio , object that responsible the communication between the server and the client.
 * @param data , the data of program.
 */
upload_unclassified::upload_unclassified(string des, DefaultIO* dio,global_data* data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data=data;
}
/**
 * getter.
 * @return this flag response for program integrity
 */
bool upload_unclassified::getFlag() {
    return flag;
}
/**
 * populates the entire folder with data structures.
 * @param str the contents of the file.
 * @return , data structures.
 */
ClassifiedArray upload_unclassified::populateTheClassified(string str) {
    ClassifiedArray array=ClassifiedArray();
    array.setVectors(PopulateVectorClassified(str));
    return array;
}
/**
 * populates the entire folder with data structures.
 * @param str the contents of the file.
 * @return , data structures.
 */
vector<NameVector> upload_unclassified::populateTheUnClassified(string str) {
    ClassifiedArray array=ClassifiedArray();
    array.setVectors(PopulateVectorUnClassified(str));
    return array.GetVectors();
}
/**
 * populates the entire folder with data structures.
 * @param str the contents of the file.
 * @return , data structures.
 */
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
/**
 * populates the entire folder with data structures.
 * @param str the contents of the file.
 * @return , data structures.
 */
vector<NameVector> upload_unclassified::PopulateVectorUnClassified(string& line)  {
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
                    dio->write("invalid input");
                    dio->read();
                }
                vec.push_back(number);
            } catch (invalid_argument &e) {
                dio->write("invalid input");
                dio->read();
            }
        }
        try {
            double number = stod(l);
            vec.push_back(number);
        }catch (invalid_argument &e){
            dio->write("invalid input");
            dio->read();
            flag= false;
            return vectors;
        }
        NameVector v("", vec);
        if (vectors.empty()) {
            vectors.push_back(v);
        } else {
            if (ValidVectors(vectors.at(0).GetVector(), vec)) {
                vectors.push_back(v);
            } else {
                dio->write("invalid input");
                dio->read();
                flag=false;
                return vectors;
            }
        }
    }
    flag=true;
    return vectors;
    }
