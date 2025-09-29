/**
 * @file SendMessageCommand.h
 * @brief Declares the SendMessageCommand class for delivering messages to chat room users.
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
 * @class SendMessageCommand
 * @brief A concrete command that sends messages to all users in a chat room.
 *
 * SendMessageCommand encapsulates the action of sending a message from one user
 * to all other users in a chat room. 
 * Delegates the actual message delivery to the ChatRoom (receiver).
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