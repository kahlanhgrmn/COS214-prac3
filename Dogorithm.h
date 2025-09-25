/**
 * @file Dogorithm.h
 * @brief Declares the Dogorithm class for managing user messages.
 * @author Gabriela
 * @date 2025-09-25
 */

#ifndef DOGORITHM_H
#define DOGORITHM_H

 #include "ChatRoom.h"
 #include <vector>
 using namespace std;

 /**
 * @class Dogorithm
 * @brief Represents a chat room where users can send and receive messages.
 *
 * The Dogorithm class stores connected users and allows them
 * to broadcast or receive messages.
 */

class Dogorithm : public ChatRoom {
    public:
        virtual ~Dogorithm();
        void registerUser(Users* user);
        void sendMessage(string message, Users* fromUser);
        void saveMessage(string message, Users* fromUser);
        void removeUser(Users* user);
};

#endif