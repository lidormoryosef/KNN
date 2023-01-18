//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_COMMAND_H
#define EX_4_COMMAND_H
#include <string>
#include "../command/global_data.h"
#include "../IO/DefaultIO.h"

using namespace std;
class Command{
protected:
    bool flag=false;
    global_data *data;
    string description ;
    DefaultIO* dio;
public:
    virtual void execute ()=0;
    virtual bool getFlag()=0;
    string getDescription();

};
#endif //EX_4_COMMAND_H
