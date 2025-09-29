/**
 * @file ModeratorUserFactory.cpp
 * @brief Implementation of ModeratorUserFactory methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "ModeratorUserFactory.h"

/**
 * @brief Create a ModeratorUser instance with moderation privileges
 * @param name The name for the moderator user
 * @return Pointer to the newly created ModeratorUser
 * 
 * Implements the factory method to create ModeratorUser objects
 * with limited administrative privileges used for content moderation.
 */
Users* ModeratorUserFactory::createUser(const string& name){
    ModeratorUser* moderator = new ModeratorUser(name);
    moderator->addPrivileges({"mute", "warn", "view_reports"});
    return moderator;
}