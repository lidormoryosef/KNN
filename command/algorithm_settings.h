//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_ALGORITHM_SETTINGS_H
#define EX_4_ALGORITHM_SETTINGS_H


#include "Command.h"
#include "server/Distance.h"
#include "server/Tools.h"

class algorithm_settings: public Command{
private:
    int k;
    Distance *distance;
    string nameDistance;

public:
    algorithm_settings(string des, DefaultIO* dio);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_ALGORITHM_SETTINGS_H
