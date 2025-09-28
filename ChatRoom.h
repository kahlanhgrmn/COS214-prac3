/**
 * @file ChatRoom.h
 * @brief Declares the ChatRoom class for managing user messages.
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef CHATROOM_H
#define CHATROOM_H

/// @brief Forward declaring that the users class exists
class Users;

#include <vector>
#include <string>
using namespace std;

 /**
 * @class ChatRoom
 * @brief Represents a chat room where users can send and receive messages.
 *
 * The ChatRoom class stores connected users and allows them
 * to broadcast or receive messages.
 */

class ChatRoom {
    protected:
        vector<Users*> users;
        vector<string> chatHistory; //can be normal string. They use String* because it can be dynamic array of string. Strings are immutable anyways.
        string name;

    public:
        ChatRoom(string n) : name(n) {}
        virtual ~ChatRoom() = default;
        virtual void registerUser(Users* user) = 0;
        virtual void sendMessage(string message, Users* fromUser) = 0; //part of receiver in command pattern
        virtual void saveMessage(string message, Users* fromUser) = 0; //part of receiver in command pattern
        virtual void removeUser(Users* user) = 0;

        const std::vector<Users*>& getUsers()const {return users;}
        const std::vector<std::string>& getChatHistory()const {return chatHistory;}

        //additional functions
        string getChatRoomName() { return name; }
        virtual void printChatRoomHistory() const = 0;
        virtual void getUserList() const = 0;
};

#endif