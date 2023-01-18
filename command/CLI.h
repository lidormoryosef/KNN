//
// Created by lidor on 1/17/23.
//

#ifndef EX_4_CLI_H
#define EX_4_CLI_H


#include "Command.h"
#include "exit_command.h"
#include "algorithm_settings.h"
#include "classify_data.h"
#include "upload_unclassified.h"
#include "display_result.h"
#include "download_results.h"
#include "../global_data.h"

class CLI {
private:
    Command* arr[7]{nullptr};
    int client_sock;
    DefaultIO* def;
    void populateArr();
    //global_data data;
public:
    //global_data getData ();
    CLI(int client_sock,DefaultIO* def);
    void start();
    bool checkValidationCommand(int choice);
};


#endif //EX_4_CLI_H
