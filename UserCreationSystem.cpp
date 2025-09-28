/**
 * @file UserCreationSystem.cpp
 * @brief Implementation of UserCreationSystem methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "UserCreationSystem.h"
#include "BasicUserFactory.h"
#include "AdminUserFactory.h"
#include "ModeratorUserFactory.h"
#include <iostream>

/**
 * @brief Construct the UserCreationSystem and register all factories
 * 
 * Initializes the system by creating instances of all
 * user factories and registering them with their type names.
 */
UserCreationSystem::UserCreationSystem(){
    factories["basic"] = new BasicUserFactory();
    factories["admin"] = new AdminUserFactory();
    factories["moderator"] = new ModeratorUserFactory();
}

/**
 * @brief Destructor that cleans up all factory instances
 * 
 * Properly deallocates all factory objects to prevent memory leaks.
 */
UserCreationSystem::~UserCreationSystem(){
    for(auto& pair: factories){

        delete pair.second;
    }
}

/**
 * @brief Create a user of the specified type
 * @param name The name for the new user
 * @param userType The type of user to create ("basic", "admin", or "moderator")
 * @return Pointer to the newly created user, or nullptr if the type is invalid
 * 
 * Routes the user creation request to the appropriate factory based on
 * the specified user type.
 */
Users* UserCreationSystem::createUser(const string& name, const string& userType){
    auto it = factories.find(userType);

    if(it != factories.end()){
        return it->second->registerNewUser(name);
    }
    
    cout << "[WARNING] Unknown user type '" << userType << "', creating basic user instead" << endl;


    return factories["basic"]->registerNewUser(name);
}

/**
 * @brief Display all available user types
 * 
 * Prints a list of all user types that can be created.
 */
void UserCreationSystem::listAvailableUserTypes()const{
    cout << "Available user types: ";

    for(const auto& pair : factories){
        cout << pair.first << " ";
    }
    
    cout << endl;
}