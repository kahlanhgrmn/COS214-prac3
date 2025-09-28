/**
 * @file Dogorithm.cpp
 * @brief Implements the Dogorithm class for managing user messages.
 * @author Gabriela
 * @date 2025-09-25
 */

 #include "Dogorithm.h"
 #include "Users.h"
 #include <iostream>
 using namespace std;

 Dogorithm::~Dogorithm() //deletion of users handled in main
 {
    users.clear(); //can't actually delete user here because it might belong to another chatroom as well.
 }

 void Dogorithm::registerUser(Users *user)
 {
    if (user == nullptr) {
        return;
    }

    users.push_back(user);

    string message = user->getName() + " joined the chat";
    saveMessage(message, nullptr);
    cout << message << endl;
 }

 void Dogorithm::sendMessage(string message, Users *fromUser)
 {
    saveMessage(message, fromUser);

    for (Users* user : users) {
        if (user != fromUser) {
            user->receive(message, fromUser, this);
        }
    }
 }

 void Dogorithm::saveMessage(string message, Users *fromUser)
 {
    chatHistory.push_back(message);
 }

 void Dogorithm::removeUser(Users *user)
 {
    if (user == nullptr) {
        return;
    }

    //user might be part of multiple chatrooms, therefore can't just delete.
    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            string message = user->getName() + " left the chatroom";
            users.erase(users.begin() + i);

            saveMessage(message, nullptr);
            cout << message << endl;
            break;
        }
    }
 }
