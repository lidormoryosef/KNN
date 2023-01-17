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

class CLI {
private:
    Command* arr[7]{nullptr};
    int client_sock;
    DefaultIO* def;
    void populateArr();
public:
    CLI(int client_sock,DefaultIO* def);
    void start();
    bool checkValidationCommand(int choice);
};


#endif //EX_4_CLI_H
