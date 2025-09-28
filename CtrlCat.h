/**
 * @file CtrlCat.h
 * @brief Declares the CtrlCat class for managing user messages.
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
 * @brief Represents a chat room where users can send and receive messages.
 *
 * The CtrlCat class stores connected users and allows them
 * to broadcast or receive messages.
 */

class CtrlCat : public ChatRoom {
    public:
        virtual ~CtrlCat();
        virtual void registerUser(Users* user);
        virtual void sendMessage(string message, Users* fromUser);
        virtual void saveMessage(string message, Users* fromUser);
        virtual void removeUser(Users* user);

};

#endif