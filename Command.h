/**
 * @file Command.h
 * @brief Declares the Command class for ...
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include <string>
#include <vector>
#include <list>
using namespace std;

/**
 * @class Command
 * @brief Represents a Command 
 *
 *
 */
class Command {
    protected:
        ChatRoom* chatRoom;
        string message;
        Users fromUser;

    public:
        virtual void execute() = 0;


};


#endif