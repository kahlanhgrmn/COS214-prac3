/**
 * @file SendMessageCommand.h
 * @brief Declares the SendMessageCommand class for ...
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
#include <string>
#include <vector>
#include <list>
using namespace std;

/**
 * @class Command
 * @brief Represents a ConcreteCommand 
 *        Implements the execute() and knows which receiver to call
 *
 */
class SendMessageCommand : public Command {
    //Has these variables inherited
    //ChatRoom* chatRoom;
    //string message;
    //Users* fromUser;
    public:
        SendMessageCommand(ChatRoom* c, string m, Users* f);
        void execute();
};


#endif