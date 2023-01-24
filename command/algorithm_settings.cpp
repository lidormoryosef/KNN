//
// Created by lidor on 1/17/23.
//

#include <sstream>
#include "algorithm_settings.h"
/**
 * this function execute option 2 in the menu.
 */
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
            string s = isValidForK(input);
            s.append("invalid value for metric");
            this->dio->write(s);
            this->dio->read();
            return;
        }
        update = input.substr(0,index);
        input = input.substr(index+1);
        try{
            tempK = stoi(update);
            }
        catch (exception &e){
            this->dio->write("invalid value for K");
            this->dio->read();
            if(whatDistance(input)==ERROR)
            {
                this->dio->write("invalid value for metric");
                this->dio->read();
            }
            return;
        }
        if ((index = input.find(' ')) != string::npos) {
            //index = input.find(' ');
            update = input.substr(0,index);
            input= input.substr(index+1);

        }
        else{
            update= input;
            input = input.substr(3);

        }
        distances dis = whatDistance(update);
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

    }
    dio->write("");
    dio->read();

}
/**
 * constructor.
 * @param des, the description of class.
 * @param dio , object that responsible the communication between the server and the client.
 * @param data , the data of program.
 */
algorithm_settings::algorithm_settings(string des, DefaultIO* dio,global_data *data) {
    this->description=std::move(des);
    this->dio=dio;
    this->data = data;
}
/**
 * getter.
 * @return this flag response for program integrity
 */
bool algorithm_settings::getFlag() {
    return flag;
}
/**
 * check if k is validly
 * @param wrong ,k
 * @return massage if the k invalid.
 */
string algorithm_settings::isValidForK(string wrong) {
    int tempK;
    try{
        tempK = stoi(wrong);
        return  "";
    }
    catch (exception &e){
        return "invalid value for K\n";

    }
}