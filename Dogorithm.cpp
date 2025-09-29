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


 /**
 * @brief Destructor for Dogorithm.
 */
 Dogorithm::~Dogorithm() //deletion of users handled in main
 {
    users.clear(); //can't actually delete user here because it might belong to another chatroom as well.
 }


 /**
 * @brief Registers a user to the Dogorithm chat room.
 * @param user Pointer to the user to be registered.
 */
 void Dogorithm::registerUser(Users *user)
 {
    if (user == nullptr) {
        return;
    }

    users.push_back(user);

    string message = "[DOGORITHM] " + user->getName() + " joined the chatroom";
    // saveMessage(message, nullptr);
    cout << message << endl;
 }


/// @brief Mediators sendMessage method. Called in User's send() method.
///        Iterates through the users list of the specific chat room and calls the user's receive method on each user beside the user that sent the massage
/// @param message is the message that was sent by a user
/// @param fromUser is a pointer to the user that sent the message
 void Dogorithm::sendMessage(string message, Users *fromUser)
 {
    for (Users* user : users) {
        if (user != fromUser) {
            user->receive(message, fromUser, this);
        }
    }
 }


 /**
 * @brief Saves a message to the chat room's history.
 * @param message The message to be saved.
 * @param fromUser Pointer to the user who sent the message.
 */
 void Dogorithm::saveMessage(string message, Users *fromUser)
 {
    chatHistory.push_back("From " + fromUser->getName() + ": " + message);
 }


 /**
 * @brief Removes a user from the CtrlCat chat room.
 * @param user Pointer to the user to be removed.
 */
 void Dogorithm::removeUser(Users *user)
 {
    if (user == nullptr) {
        return;
    }

    //user might be part of multiple chatrooms, therefore can't just delete.
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            string message = "[" + this->getChatRoomName() + "] " + user->getName() + " left the chatroom";
            users.erase(users.begin() + i);

            // saveMessage(message, nullptr);
            cout << message << endl;
            break;
        }
    }
 }


 /**
 * @brief Prints the complete chat history of the room.
 */
 void Dogorithm::printChatRoomHistory() const
 {
    cout << "\n=== Dogorithm Chat History ===" << endl;
    if (chatHistory.empty()) {
        cout << "No messages in Dogorithm history." << endl;
    } else {
        for (size_t i = 0; i < chatHistory.size(); i++) {
            cout << "[" << i + 1 << "] " << chatHistory[i] << endl;
        }
    }
    cout << "===============================" << endl;
 }


 /**
 * @brief Prints the list of all users currently in the room.
 */
 void Dogorithm::getUserList() const
 {
    cout << "\n=== Dogorithm Users ===" << endl;
    if (users.empty()) {
        cout << "No users in chatroom." << endl;
    } else {
        for (size_t i = 0; i < users.size(); i++) {
            cout << users[i]->getName() << endl;
        }
    }
    cout << "============================" << endl;
 }
