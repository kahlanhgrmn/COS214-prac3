/**
 * @file ModeratorUser.h
 * @brief Moderator user with limited administrative privileges
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#ifndef MODERATOR_USER_H
#define MODERATOR_USER_H

#include "Users.h"
#include <vector>
using namespace std;

/**
 * @class ModeratorUser
 * @brief Moderator user with content moderation capabilities
 * 
 * This class represents a moderator who has basic user capabilities
 * and limited admin privileges like muting users and issuing warnings.
 */
class ModeratorUser: public Users{
    private:
        vector<string> privileges;
    public:
        explicit ModeratorUser(const string& userName);
        void addPrivileges(const vector<string>& privs);
        bool hasPrivilege(const string& privilege)const override;
        string getUserType()const override;
        void muteUser(Users* user, ChatRoom* room);
        void warnUser(Users* user, const string& reason);
        void viewUserReports(ChatRoom* room);
};

#endif