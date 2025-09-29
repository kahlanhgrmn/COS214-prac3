/**
 * @file UserFactory.h
 * @brief Abstract factory for creating Users
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef USER_FACTORY_H
#define USER_FACTORY_H

#include "Users.h"
using namespace std;

/**
 * @class UserFactory
 * @brief Abstract creator class for the Factory Method pattern
 * 
 * Defines the interface for creating Users objects.
 * Concrete factory subclasses will implement the createUser method
 * to create specific types of users.
 */
class UserFactory{
    public:
        virtual ~UserFactory() = default;
        virtual Users* createUser(const string& name) = 0;
        Users* registerNewUser(const string& name);
};

#endif