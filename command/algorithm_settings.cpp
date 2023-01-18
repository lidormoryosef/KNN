//
// Created by lidor on 1/17/23.
//

#include <sstream>
#include "algorithm_settings.h"
#include "server/EuclideanDistance.h"

void algorithm_settings::execute() {
    string message = "", input , update;
    int tempK = this->data->getK();
    message = message.append ("The current KNN parameters are: K = ");
    message = message.append(to_string(tempK));
    message = message.append(", distance metric = ");
    message = message.append(this->data->getNameNorm());
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
            this->data->setK(tempK);
            this->data->setNorm( tempDis);
            this->data->setNameNorm(tempName);
        } else {
            this->dio->write("too many arguments");
        }
    }
}

algorithm_settings::algorithm_settings(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
    this->data->setK(5);
    this->data->setNorm(new EuclideanDistance);
    this->data->setNameNorm("EUC");
}

bool algorithm_settings::getFlag() {
    return flag;
}
