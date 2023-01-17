//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_ALGORITHM_SETTINGS_H
#define EX_4_ALGORITHM_SETTINGS_H


#include "Command.h"

class algorithm_settings: public Command{

public:
    algorithm_settings(string des, DefaultIO* dio);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_ALGORITHM_SETTINGS_H
