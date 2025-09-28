/**
 * @file AdminUserFactory.cpp
 * @brief Implementation of AdminUserFactory methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "AdminUserFactory.h"

/**
 * @brief Create a AdminUser instance with full privileges
 * @param name The name for the admin user
 * @return Pointer to the newly created AdminUser
 * 
 * Implements the factory method to create AdminUser objects
 * with full administrative privileges including kick, ban, and delete.
 */
Users* AdminUserFactory::createUser(const string& name){
    AdminUser* admin = new AdminUser(name);
    admin->addPrivileges({"kick", "ban", "delete_messages", "view_logs"});
    return admin;
}