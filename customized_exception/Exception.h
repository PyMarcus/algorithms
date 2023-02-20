//
// Created by marcus on 2/19/23.
//

#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H
#include <iostream>
#include <exception>
#include <utility>
#include <string.h>


class Exception: public std::exception {
    /*
     * Exception  class
     * that define a exception message
     * */
protected:
    char message[100];
public:
    Exception(const char *message){
        stpcpy(this->message, message);
    }

    virtual const char* what();
};


#endif //STACK_EXCEPTION_H
