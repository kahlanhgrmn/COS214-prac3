/**
 * @file UserCreationSystem.h
 * @brief System for managing user creation through factories
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef USER_CREATION_SYSTEM_H
#define USER_CREATION_SYSTEM_H

#include "UserFactory.h"
#include <map>
using namespace std;

/**
 * @class UserCreationSystem
 * @brief Manages multiple user factories and coordinates user creation
 * 
 * This class provides an interface for creating different types
 * of users by managing various factory instances.
 */
class UserCreationSystem{
    private:
        map<string, UserFactory*> factories;
    public:
        UserCreationSystem();
        ~UserCreationSystem();
        Users* createUser(const string& name, const string& userType);
        void listAvailableUserTypes()const;
};

#endif