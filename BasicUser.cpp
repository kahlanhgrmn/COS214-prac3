/**
 * @file BasicUser.h
 * @brief Implementation of the BasicUser methods
 * @author Kahlan Hagerman
 * @date 2025-09-27
 */

#include "BasicUser.h"

/**
 * @brief Construct a BasicUser with a given user name
 * @param userName The name given to the basic user
 * 
 * Create a basic user with normal chat capabilities. They can send and receive messages
 * but they have no special privileges.
 */
BasicUser::BasicUser(const std::string& userName): Users(userName){}

/**
 * @brief Get the type of user
 * @param String "Basic" which shows that it is a basic user
 * 
 * Return the type of user which is used to differentiate between users in the system.
 */
std::string BasicUser::getUserType()const{
    return "Basic";
}

