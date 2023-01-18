//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_COMMAND_H
#define EX_4_COMMAND_H
#include "global_data.h"
#include <string>
#include "IO/DefaultIO.h"

using namespace std;
class Command{
protected:
    bool flag=false;
public:
    global_data *data;
    string description ;
    DefaultIO* dio;
    virtual void execute ()=0;
    virtual bool getFlag()=0;

};
#endif //EX_4_COMMAND_H
