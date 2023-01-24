//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_EXIT_COMMAND_H
#define EX_4_EXIT_COMMAND_H

#include "Command.h"
/**
 * this class response for free memory and close the socket.
 */
class exit_command: public Command{
public:
    exit_command(string des, DefaultIO* dio,global_data* data);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_EXIT_COMMAND_H
