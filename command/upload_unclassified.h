//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_UPLOAD_UNCLASSIFIED_H
#define EX_4_UPLOAD_UNCLASSIFIED_H

#include "Command.h"
#include "../server/ClassifiedArray.h"

class upload_unclassified: public Command{
private:
    ClassifiedArray classifiedArray;
    ClassifiedArray unClassifiedArray;
public:
   upload_unclassified(string des,DefaultIO* dio,global_data* data);
    void execute () override;
    bool getFlag() override;
    ClassifiedArray populateArrays(bool check);
};


#endif //EX_4_UPLOAD_UNCLASSIFIED_H
