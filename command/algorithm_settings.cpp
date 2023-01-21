//
// Created by lidor on 1/17/23.
//

#include <sstream>
#include "algorithm_settings.h"

void algorithm_settings::execute() {
    string message = "", input , update;
    int tempK = this->data->getK();
    message = message.append ("The current KNN parameters are: K = ");
    message = message.append(to_string(tempK));
    message = message.append(", distance metric = ");
    message = message.append(this->data->getNameNorm());
    this->dio->write(message);
    input = this->dio->read();
    size_t index;
    if (!input.empty()) {
        if ((index = input.find(' ')) == string::npos){
            this->dio->write("invalid value for metric");
            this->dio->read();
            return;
        }
        //stringstream str(input);
        //getline(str, update, ' ');
        update = input.substr(0,index);
        input = input.substr(index+1);
        try{
            tempK = stoi(update);
            }
        catch (exception &e){
            this->dio->write("invalid value for K");
            this->dio->read();
            return;
        }
        if ((index = input.find(' ')) != string::npos) {
            index = input.find(' ');
            update = input.substr(0,index);
            input= input.substr(index+1);
        }
        else{
            update= input;
            input = input.substr(3);

        }
        //getline(str, update, ' ');
        //index = input.find(' ');
        //update = input.substr(0, index);
        //string tempName = update;
        distances dis = whatDistance(update);
        //update="";
        //input = input.substr(index+4);
        //getline(str, update, ' ');
        Distance *tempDis;
        tempDis = GetDistanceFun(dis);
        if (tempDis == nullptr) {
            this->dio->write("invalid value for metric");
            this->dio->read();
            return;
        }
        if (input.empty()) {
            this->data->setK(tempK);
            free(this->data->getNorm());
            this->data->setNorm( tempDis);
            this->data->setNameNorm(update);
        } else {
            this->dio->write("too many arguments");
            this->dio->read();
            return;
        }
        dio->write("");
        dio->read();
    }
}

algorithm_settings::algorithm_settings(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}

bool algorithm_settings::getFlag() {
    return flag;
}
