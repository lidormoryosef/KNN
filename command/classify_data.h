//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_CLASSIFY_DATA_H
#define EX_4_CLASSIFY_DATA_H
#include "../server/Tools.h"
#include "Command.h"
#include "algorithm"
#include "../server/Distance.h"
/**
 * this class response for classification of data.
 */
class classify_data: public Command{
public:
    void PopulateDistance(const vector<double>& compare);
    string KNN(const vector<double>& compare);

    classify_data(string des, DefaultIO* dio,global_data *data);
    void execute () override;
    bool getFlag() override;
    void SortByValue();
    string FindClassification();
};


#endif //EX_4_CLASSIFY_DATA_H
