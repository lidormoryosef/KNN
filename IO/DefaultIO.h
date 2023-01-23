//
// Created by lidor on 1/17/23.
//
# include <string>
#ifndef EX_4_DEFAULTIO_H
#define EX_4_DEFAULTIO_H
using namespace std;
/**
 * responsible for the interface between the client and the server.
 */
class DefaultIO{
public:
    virtual string read ()=0;
    virtual void write (string str)=0;
};
#endif //EX_4_DEFAULTIO_H
