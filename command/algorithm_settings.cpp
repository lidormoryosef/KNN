//
// Created by lidor on 1/17/23.
//

#include <sstream>
#include "algorithm_settings.h"
#include "server/EuclideanDistance.h"

void algorithm_settings::execute() {
    string message = "", input , update;
    int tempK = this->k;
    message = message.append ("The current KNN parameters are: K = ");
    message = message.append(to_string(this->k));
    message = message.append(", distance metric = ");
    message = message.append(this->nameDistance);
    this->dio->write(message);
    input = this->dio->read();
    if (!input.empty()) {
        stringstream str(input);
        getline(str, update, ' ');
        if (IsValidK(update))
            tempK = stoi(update);
        else
            this->dio->write("invalid value for K");
        getline(str, update, ' ');
        string tempName = update;
        distances dis = whatDistance(update);
        getline(str, update, ' ');
        Distance *tempDis;
        tempDis = GetDistanceFun(dis);
        if (tempDis == nullptr)
            this->dio->write("invalid value for metric");
        else if (update.empty()) {
            this->k = tempK;
            this->distance = tempDis;
            this->nameDistance = tempName;
        } else {
            this->dio->write("too many arguments");
        }
    }
}

algorithm_settings::algorithm_settings(string des, DefaultIO* dio) {
    this->description=std::move(des);
    this->dio=dio;
    this->k = 5;
    this->distance= new EuclideanDistance;
    this->nameDistance = "EUC";
}

bool algorithm_settings::getFlag() {
    return flag;
}
