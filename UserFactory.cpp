/**
 * @file UserFactory.cpp
 * @brief Implementation of UserFactory methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "UserFactory.h"
#include <iostream>

/**
 * @brief Register a new user using the factory method
 * @param name The name for the new user
 * @return Pointer to the created user
 * 
 * Uses the factory method to create a user
 * and performs common initialisation tasks. Actual user creation
 * is delegated to the concrete factory's "createUser" method.
 */
Users* UserFactory::registerNewUser(const string& name){
    Users* user = createUser(name);

    cout << "[FACTORY] Created new " << user->getUserType() << " user: " << user->getName() << endl;


    return user;
}