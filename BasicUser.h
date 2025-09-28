/**
 * @file BasicUser.h
 * @brief Standard user with basic chat functionality
 * @author Kahlan Hagerman
 * @date 2025-09-27
 */

#ifndef BASIC_USER_H
#define BASIC_USER_H

#include "Users.h"
using namespace std;

/**
 * @class BasicUser
 * @brief Standard user implementation with the basic chat functionalities.
 * 
 * This class will represent a normal user that can send and receive messages, 
 * and can participate in different chat rooms without any privileges.
 */
class BasicUser: public Users{
    public:
        explicit BasicUser(const std::string& userName);
        std::string getUserType()const override;
};

#endif