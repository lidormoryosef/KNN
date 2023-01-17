//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_CLASSIFY_DATA_H
#define EX_4_CLASSIFY_DATA_H

#include "Command.h"
class classify_data: public Command{
public:
    classify_data(string des, DefaultIO* dio);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_CLASSIFY_DATA_H
