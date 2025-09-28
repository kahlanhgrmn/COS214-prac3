/**
 * @file Users.cpp
 * @brief Implements the Users class for managing user actions.
 * @author Gabriela
 * @date 2025-09-16
 */

 #include "ChatRoom.h"
 #include "Command.h"
 #include "SendMessageCommand.h"
 #include "SaveMessageCommand.h"
 #include "Users.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <list>
 using namespace std;

 /// @brief User's send method. Used when a user want to send a message to a specific chat room. 
 ///        User doesn't know about other users. User only knows about the mediator (ChatRoom)
 /// @param message is the message the user wants to send
 /// @param room is the chatroom the user whats to send the message in.
 void Users::send(string message, ChatRoom* room)
 {
   Command* sendMessageCmd = new SendMessageCommand(room, message, this);
   Command* saveMessageCmd = new SaveMessageCommand(room, message, this);
   commandQueue.push_back(sendMessageCmd);
   commandQueue.push_back(saveMessageCmd);
   executeAll();
 }

 
 /// @brief Shows the user received a message from another user.
 ///        Called in the concreteMediator's sendMessage() method.
 /// @param message is the message received from another user
 /// @param fromUser is the user that sent the message
 /// @param room is the chatroom the message was sent in.
 void Users::receive(string message, Users *fromUser, ChatRoom *room)
 {
    cout << "[" << room->getChatRoomName() << "] " << name << " received from " << fromUser->getName() << " : " << message << endl;
 }

 void Users::addCommand(Command* command)
 {
   if (command == nullptr) {
      return;
   }
   commandQueue.push_back(command);
 }

 void Users::executeAll()
 {
   for (Command* cmd : commandQueue) {
      cmd->execute(); 
      delete cmd; //cleaning up memory
   }
   commandQueue.clear();
 }
