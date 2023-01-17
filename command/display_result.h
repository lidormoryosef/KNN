//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_DISPLAY_RESULT_H
#define EX_4_DISPLAY_RESULT_H

#include "Command.h"
class display_result: public Command{
public:
    display_result(string des, DefaultIO* dio);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_DISPLAY_RESULT_H
