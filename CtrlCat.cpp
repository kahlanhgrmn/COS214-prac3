/**
 * @file CtrlCat.cpp
 * @brief Implements the CtrlCat class for managing user messages.
 * @author Gabriela
 * @date 2025-09-16
 */

 #include "CtrlCat.h"
 #include "Users.h"
 #include <iostream>
 using namespace std;

 /// @brief Destructor for the CtrlCat deallocates dynamically allocated users
 CtrlCat::~CtrlCat()
{
    users.clear();
}


/// @brief 
/// @param user is the user that needs to be registered in the ctrlcat chatroom.
void CtrlCat::registerUser(Users* user) {
    if (user == nullptr) {
        return;
    }

    users.push_back(user);

    string message = "[CTRLCAT] " + user->getName() + " joined the chatroom";
    // saveMessage(message, nullptr);
    cout << message << endl;
}


/// @brief Mediators sendMessage method. Called in User's send() method.
///        Saves the message to the chat room's message history.
///        Iterates through the users list of the specific chat room and calls the user's receive method on each user beside the user that sent the massage
/// @param message is the message that was sent by a user
/// @param fromUser is the user that sent the message
void CtrlCat::sendMessage(string message, Users* fromUser)
{
    for (Users* user : users) {
        if (user != fromUser) {
            user->receive(message, fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(string message, Users *fromUser)
{
    chatHistory.push_back("From " + fromUser->getName() + ": " + message);
}

void CtrlCat::removeUser(Users *user)
{
    if (user == nullptr) {
        return;
    }

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            string message = "[" + this->getChatRoomName() + "] " + user->getName() + " left the chatroom";
            users.erase(users.begin() + i); //can't delete user because they may be part of multiple chat rooms

            // saveMessage(message, nullptr);
            cout << message << endl;
            break;
        }
    }
}

void CtrlCat::printChatRoomHistory() const
{
    cout << "\n=== CtrlCat Chat History ===" << endl;
    if (chatHistory.empty()) {
        cout << "No messages in CtrlCat history." << endl;
    } else {
        for (size_t i = 0; i < chatHistory.size(); i++) {
            cout << "[" << i + 1 << "] " << chatHistory[i] << endl;
        }
    }
    cout << "============================" << endl;

}

void CtrlCat::getUserList() const
{
    cout << "\n=== CtrlCat Users ===" << endl;
    if (users.empty()) {
        cout << "No users in chatroom." << endl;
    } else {
        for (size_t i = 0; i < users.size(); i++) {
            cout << users[i]->getName() << endl;
        }
    }
    cout << "============================" << endl;
}
