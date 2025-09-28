/**
 * @file AdminUser.h
 * @brief Administrator user with full system privileges
 * @author Kahlan Hagerman
 * @date 2025-09-27
 */

#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include "Users.h"
#include <string>
#include <vector> 
using namespace std;

/**
 * @class AdminUser
 * @brief Administrator user with full system control
 * 
 * Represents an administrator who will have all of the basic user
 * capabilities as well as fully system privileges and control like
 * kicking or banning users, and managing chat rooms.
 */
class AdminUser: public Users{
    private:
        vector<string> privileges;
    public:
        explicit AdminUser(const string& userName);
        void addPrivileges(const vector<string>& priv);
        bool hasPrivilege(const string& privilege)const override;
        string getUserType()const override;
        void kickUser(Users* user, ChatRoom* room);
        void banUser(Users* user, ChatRoom* room);
        void deleteMessage(ChatRoom* room, int messageIndex);

};

#endif