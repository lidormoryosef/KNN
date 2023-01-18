//
// Created by lidor on 1/17/23.
//

#include "upload_unclassified.h"
#include "../server/ClassifiedArray.h"

#include <utility>

void upload_unclassified::execute() {
    dio->write("Please upload your local train CSV file.");
    bool check=false;
    this->classifiedArray=populateArrays(check);
    dio->write("Upload complete.");
    dio->write("Please upload your local test CSV file.");
    check=true;
    this->unClassifiedArray=populateArrays(check);
    dio->write("Upload complete.");

}

upload_unclassified::upload_unclassified(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;
}

bool upload_unclassified::getFlag() {
    return flag;
}

ClassifiedArray upload_unclassified::populateArrays(bool check) {
    string str=dio->read();
    ClassifiedArray array=ClassifiedArray();
    int len=str.size()-1;
    string last=str.substr(0,len-1);
    if(!check){
        array.PopulateVector1(last);
    }else{
        array.PopulateVector2(last);
    }
    return array;
}
