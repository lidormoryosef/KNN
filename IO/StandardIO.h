//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_STANDARDIO_H
#define EX_4_STANDARDIO_H


#include "DefaultIO.h"
/**
 * responsible for the interface between the client and the server by keyboard.
 */
class StandardIO: public DefaultIO{

public:
    string read() override;
    void write (string str) override;
};


#endif //EX_4_STANDARDIO_H
