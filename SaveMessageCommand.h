/**
 * @file SaveMessageCommand.h
 * @brief Declares the SaveMessageCommand class for storing messages in chat history.
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
 * @brief A concrete command that saves messages to all chat room's history.
 *
 * SaveMessageCommand encapsulates the action of persisting a message to the chat
 * room's history for later retrieval.
 * Delegates the actual saving to the ChatRoom (receiver).
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