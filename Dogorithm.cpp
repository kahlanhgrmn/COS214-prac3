/**
 * @file Dogorithm.cpp
 * @brief Implements the Dogorithm class for managing user messages.
 * @author Gabriela
 * @date 2025-09-25
 */

 #include "Dogorithm.h"
 #include <iostream>
 using namespace std;

 Dogorithm::~Dogorithm()
 {
    for (Users* user : users) {
        delete user;
    }
    users.clear();
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
    if (fromUser == nullptr) {
        return;
    }

    chatHistory.push_back(message);
 }

 void Dogorithm::removeUser(Users *user)
 {
    if (user == nullptr) {
        return;
    }

    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            string message = user->getName() + " left the chatroom";
            delete user;
            users.erase(users.begin() + i);

            saveMessage(message, nullptr);
            cout << message << endl;
        }
    }
 }
