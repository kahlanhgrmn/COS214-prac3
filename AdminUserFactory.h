/**
 * @file AdminUserFactory.h
 * @brief Concrete factory for creating AdminUser objects
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef ADMIN_USER_FACTORY_H
#define ADMIN_USER_FACTORY_H

#include "UserFactory.h"
#include "AdminUser.h"

/**
 * @class AdminUserFactory
 * @brief Concrete creator for AdminUser objects
 * 
 * Creates AdminUser instances with full administrative
 * privileges, implementing the createUser factory method.
 */
class AdminUserFactory: public UserFactory{
    public:
        Users* createUser(const string& name)override;
};

#endif