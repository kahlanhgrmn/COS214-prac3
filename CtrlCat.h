/**
 * @file CtrlCat.h
 * @brief Declares the CtrlCat concrete chat room class.
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef CTRLCAT_H
#define CTRLCAT_H

 #include "ChatRoom.h"
 #include <vector>
 using namespace std;

 /**
 * @class CtrlCat
 * @brief A concrete chat room implementation where users that like cats can send and receive messages
 *
 * CtrlCat is a concrete mediator that manages communication between users
 * interested in cat-related topics and technology. It handles user registration,
 * message broadcasting, and chat history management.
 */

class CtrlCat : public ChatRoom {
    public:
        /**
         * @brief Constructs a CtrlCat chat room.
         */
        CtrlCat(string n) : ChatRoom(n) {}
        virtual ~CtrlCat();
        virtual void registerUser(Users* user);
        virtual void sendMessage(string message, Users* fromUser);
        virtual void saveMessage(string message, Users* fromUser);
        virtual void removeUser(Users* user);

        //additional
        virtual void printChatRoomHistory() const;
        virtual void getUserList() const;

};

#endif