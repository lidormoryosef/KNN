//
// Created by lidor on 1/17/23.
//
# include <string>
#ifndef EX_4_DEFAULTIO_H
#define EX_4_DEFAULTIO_H
using namespace std;
class DefaultIO{
public:
    virtual string read ()=0;
    virtual void write (string str)=0;
};
#endif //EX_4_DEFAULTIO_H
