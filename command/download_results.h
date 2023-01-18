//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_DOWNLOAD_RESULTS_H
#define EX_4_DOWNLOAD_RESULTS_H

#include "Command.h"
class download_results: public Command{
public:
    download_results(string des, DefaultIO* dio,global_data* data);
    void execute () override;
    bool getFlag() override;
};


#endif //EX_4_DOWNLOAD_RESULTS_H
