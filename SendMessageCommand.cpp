#include "SendMessageCommand.h"

SendMessageCommand::SendMessageCommand(ChatRoom *c, string m, Users* f) : Command(c, m, f) {}

void SendMessageCommand::execute()
{
    chatRoom->sendMessage(message, fromUser);
}