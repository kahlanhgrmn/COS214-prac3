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
    Name1() : Users("Alice") {}
};

class Name2 : public Users {
public:
    Name2() : Users("Bob") {}
};

class Name3 : public Users {
public:
    Name3() : Users("Charlie") {}
};


#endif