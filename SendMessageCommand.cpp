/**
 * @file SendMessageCommand.cpp
 * @brief Implements the SendMessageCommand class.
 * @author Gabriela
 * @date 2025-09-29
 */

#include "SendMessageCommand.h"


/**
 * @brief Constructs a SendMessageCommand with the specified parameters.
 * @param c Pointer to the ChatRoom where the message will be sent.
 * @param m The message content to be delivered.
 * @param f Pointer to the user sending the message.
 */
SendMessageCommand::SendMessageCommand(ChatRoom *c, string m, Users* f) : Command(c, m, f) {}


/**
 * @brief Executes the command by calling the chat room's sendMessage method.
 *
 * This method delegates to the ChatRoom receiver to broadcast the message
 * to all users except the sender.
 */
void SendMessageCommand::execute()
{
    chatRoom->sendMessage(message, fromUser);
}