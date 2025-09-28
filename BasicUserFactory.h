/**
 * @file BasicUserFactory.h
 * @brief Concrete factory for creating BasicUser objects
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef BASIC_USER_FACTORY_H
#define BASIC_USER_FACTORY_H

#include "UserFactory.h"
#include "BasicUser.h"

/**
 * @class BasicUserFactory
 * @brief Concrete creator for BasicUser objects
 * 
 * This factory creates BasicUser instances, implementing the
 * createUser factory method for standard users.
 */
class BasicUserFactory: public UserFactory{
    public:
        Users* createUser(const string& name)override;
};

#endif