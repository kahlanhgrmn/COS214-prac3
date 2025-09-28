/**
 * @file SaveMessageCommand.h
 * @brief Declares the SaveMessageCommand class for ...
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef SaveMessageCommand_H
#define SaveMessageCommand_H

#include "Command.h"
#include <string>
#include <vector>
#include <list>
using namespace std;

/**
 * @class SaveMessageCommand
 * @brief Represents a Command 
 *
 *
 */
class SaveMessageCommand : public Command {
    //Has these variables inherited
    //ChatRoom* chatRoom;
    //string message;
    //Users* fromUser;
    public:
        SaveMessageCommand(ChatRoom* c, string m, Users* u);
        void execute();


};


#endif