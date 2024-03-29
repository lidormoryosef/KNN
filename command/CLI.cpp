//
// Created by lidor on 1/17/23.
//

#include "CLI.h"
#include "../server/Tools.h"
/**
 * run the program.
 */
void CLI::start() {
    while (true) {
        string massage = "";
        massage.append("Welcome to the KNN Classifier Server. Please choose an option:\n");
        for (int i = 1; i < 7; ++i) {
            massage.append(arr[i]->getDescription());
        }
        this->def->write(massage);
        //def->read();
        //def->write("");
        int choice;
        string str = def->read();
        if (str.empty()) {
            //def->write("");
            break;
        }
        if (IsValidK(str)) {
            choice = stoi(str);
        } else {
            this->def->write("invalid choice, try again.");
            this->def->read();
            continue;
        }
        if (choice==8) {
            arr[6]->execute();
            for (int i = 1; i < 7; ++i) {
                free(arr[i]);
            }
            break;
        }
        if(choice>0&&choice<6) {
            if (checkValidationCommand(choice)) {
                arr[choice]->execute();
            }else {
                if (!arr[1]->getFlag())
                    this->def->write("please upload data");
                else
                    this->def->write("please classify the data");
                def->read();
                continue;

            }
        }else
        {
            this->def->write("invalid choice, try again.");
            this->def->read();
        }


    }

}
/**
 * constructor.
 * @param def object that responsible the communication between the server and the client.
 */
CLI::CLI( DefaultIO *def) {
  //  this->client_sock=client_sock;
    this->def=def;
    populateArr();
}
/**
 * populating the array of commands.
 */
void CLI::populateArr() {
    global_data *data = new global_data();
    this->arr[1]=new upload_unclassified("1. upload an unclassified csv data file\n", this->def,data);
    this->arr[2]=new algorithm_settings("2. algorithm setting\n", this->def,data);
    this->arr[3]=new classify_data("3. classify data\n", this->def,data);
    this->arr[4]=new display_result("4. display results\n", this->def,data);
    this->arr[5]=new download_results("5. download results \n", this->def,data);
    this->arr[6]=new exit_command("8. exit", this->def,data);
}
/**
 * verifies the correctness of the program.
 * @param choice , the choice of client.
 * @return
 */
bool CLI::checkValidationCommand(int choice) {
    if(choice==3)
        return arr[1]->getFlag();
    if(choice==4||choice==5)
        return arr[3]->getFlag();
    return true;
}
