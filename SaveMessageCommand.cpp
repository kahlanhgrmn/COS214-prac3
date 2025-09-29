/**
 * @file SaveMessageCommand.cpp
 * @brief Implements the SaveMessageCommand class.
 * @author Gabriela
 * @date 2025-09-29
 */

#include "SaveMessageCommand.h"

/// @brief Constructs a SaveMessageCommand and initializes base Command attributes.
/// @param c Pointer to the target ChatRoom.
/// @param m Message content to save.
/// @param u Pointer to the user who sent the message.
SaveMessageCommand::SaveMessageCommand(ChatRoom * c, string m, Users* u) : Command(c, m, u) {}


/// @brief Executes the command by delegating message storage to the chat room.
void SaveMessageCommand::execute()
{
    chatRoom->saveMessage(message, fromUser); //calling receivers saveMessage method
}
