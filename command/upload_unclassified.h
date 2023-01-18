//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_UPLOAD_UNCLASSIFIED_H
#define EX_4_UPLOAD_UNCLASSIFIED_H
#include "upload_unclassified.h"
#include "../IO/DefaultIO.h"
#include  <sstream>
#include <utility>
#include "../server/Tools.h"
#include "Command.h"
#include "../server/ClassifiedArray.h"
#include "../IO/DefaultIO.h"
#include "global_data.h"

class upload_unclassified: public Command{
public:
   upload_unclassified(string des,DefaultIO* dio,global_data* data);
    void execute () override;
    bool getFlag() override;
    ClassifiedArray populateTheClassified();
    vector<NameVector> populateTheUnClassified();

    vector<NameVector> PopulateVectorClassified(const string& line);

    vector<NameVector> PopulateVectorUnClassified(const string& line);
};


#endif //EX_4_UPLOAD_UNCLASSIFIED_H
