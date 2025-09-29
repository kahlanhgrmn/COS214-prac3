/**
 * @file BasicUserFactory.cpp
 * @brief Implementation of BasicUserFactory methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "BasicUserFactory.h"

/**
 * @brief Create a BasicUser instance
 * @param name The name for the basic user
 * @return Pointer to the created BasicUser
 * 
 * Implements the factory method to create BasicUser objects
 * with chat capabilities and no special privileges.
 */
Users* BasicUserFactory::createUser(const string& name){
    return new BasicUser(name);
}