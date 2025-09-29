/**
 * @file Command.h
 * @brief Declares the Command abstract base class for command interface.
 * @author Gabriela
 * @date 2025-09-29
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
 * @brief Abstract base class for commands in the Command pattern.
 *
 * Command encapsulates chat operations as objects. Handles
 * sending and saving messages. Concrete commands delegate execution
 * to the ChatRoom receiver.
 */
class Command {
    protected:
        ChatRoom* chatRoom;
        string message;
        Users* fromUser;

    public:

        /**
         * @brief Constructs a Command with the specified parameters.
         * @param c Pointer to the ChatRoom receiver.
         * @param m The message content.
         * @param u Pointer to the user initiating the command.
         */
        Command(ChatRoom* c, string m, Users* u) : chatRoom(c), message(m), fromUser(u) {}

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~Command () {}

        /**
         * @brief Executes the command.
         *
         * Pure virtual method and must be implemented by concrete command classes
         * to perform their specific action by calling the appropriate receiver method.
         */
        virtual void execute() = 0;
};


#endif