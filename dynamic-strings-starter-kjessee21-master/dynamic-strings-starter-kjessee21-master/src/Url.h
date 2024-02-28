//
// Created by Kaden Jessee on 8/18/2022.
//

#ifndef URLTESTING_URL_H
#define URLTESTING_URL_H
#include "DynamicString.h"
#include <iostream>

class Url : public DynamicString{
public:
    Url(const char* str);
    int compare(const Url& other);
private:
    DynamicString scheme;
    DynamicString authority;
    DynamicString path;
};
#endif //URLTESTING_URL_H
