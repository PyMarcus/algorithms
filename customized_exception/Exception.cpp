//
// Created by marcus on 2/19/23.
//

#include "Exception.h"


const char* Exception::what(){
    return this->message;
}
