#include "SaveMessageCommand.h"

SaveMessageCommand::SaveMessageCommand(ChatRoom * c, string m, Users* u) : Command(c, m, u) {}

void SaveMessageCommand::execute()
{
    chatRoom->saveMessage(message, fromUser); //calling receivers saveMessage method
}
