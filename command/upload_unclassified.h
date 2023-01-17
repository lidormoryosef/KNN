//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_UPLOAD_UNCLASSIFIED_H
#define EX_4_UPLOAD_UNCLASSIFIED_H

#include "Command.h"

class upload_unclassified: public Command{
public:
   upload_unclassified(string des,DefaultIO* dio);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_UPLOAD_UNCLASSIFIED_H
