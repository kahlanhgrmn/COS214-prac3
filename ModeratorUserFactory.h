/**
 * @file ModeratorUserFactory.h
 * @brief Concrete factory for creating ModeratorUser objects
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef MODERATOR_USER_FACTORY_H
#define MODERATOR_USER_FACTORY_H

#include "UserFactory.h"
#include "ModeratorUser.h"

/**
 * @class ModeratorUserFactory
 * @brief Concrete creator for ModeratorUser objects
 * 
 * This factory creates ModeratorUser instances with some
 * administrative privileges, implementing the createUser factory method.
 */
class ModeratorUserFactory: public UserFactory{
    public:
        Users* createUser(const string& name)override;
};

#endif