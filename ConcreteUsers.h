/**
 * @file ConcreteUsers.h
 * @brief Declares the ConcreteUsers class for managing user messages.
 * @author Gabriela
 * @date 2025-09-28
 */

#ifndef CONCRETEUSERS_H
#define CONCRETEUSERS_H

#include "Users.h"
#include <string>

class Name1 : public Users {
public:
    Name1(string n) : Users(n) {}
    ~Name1() {}
};

class Name2 : public Users {
public:
    Name2(string n) : Users(n) {}
    ~Name2() {}
};

class Name3 : public Users {
public:
    Name3(string n) : Users(n) {}
    ~Name3() {}
};


#endif