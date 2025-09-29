/**
 * @file AdminUser.cpp
 * @brief Implementation of the AdminUser methods
 * @author Kahlan Hagerman
 * @date 2025-09-27
 */

#include "AdminUser.h"
#include "ChatRoom.h"
#include <iostream>

/**
 * @brief Construct an AdminUser with the given name
 * @param userName The name for this admin user
 * 
 * Creates an admin user with full system privileges.
 * Admin users have all capabilities of basic users plus administrative functions.
 */
AdminUser::AdminUser(const string& userName): Users(userName){}

/**
 * @brief Add administrative privileges to an admin user
 * @param privs Vector of privilege strings to grant to this admin
 * 
 * Sets the admin privileges that this admin user has, such as kick, ban, 
 * and deleting messages.
 */
void AdminUser::addPrivileges(const vector<string>& privs){
    privileges = privs;
}

/**
 * @brief Check if this admin user has a specific privilege
 * @param privilege The privilege to check for
 * @return true if the admin has this privilege, false if not
 * 
 * Verifies whether this admin has been granted the specified
 * privilege, allowing for permission control.
 */
bool AdminUser::hasPrivilege(const string& privilege)const{
    for(const string& priv: privileges){
        if(priv == privilege){
            return true;
        }
    }

    return false;
}

/**
 * @brief Get the type of this user
 * @return String "Admin" indicating this is an administrator
 * 
 * Returns the user type used to distinguish administrators
 * from other user types in the system.
 */
string AdminUser::getUserType()const{
    return "Admin";
}

/**
 * @brief Kick a user from the specified chat room
 * @param user The user to kick from the room
 * @param room The chat room to kick the user from
 * 
 * Removes the specified user from the chat room if this admin
 * has the "kick" privilege.
 */
void AdminUser::kickUser(Users* user, ChatRoom* room){
    if(hasPrivilege("kick")){
        room->removeUser(user);

        cout << "[ADMIN ACTION] " << getName() << " kicked " << user->getName()  << " from " << room->getChatRoomName() << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have kick privileges" << endl;
    }
}

/**
 * @brief Ban a user from the specified chat room
 * @param user The user to ban from the room
 * @param room The chat room to ban the user from
 * 
 * Permanently removes the specified user from the chat room if this admin
 * has the "ban" privilege.
 */
void AdminUser::banUser(Users* user, ChatRoom* room){
    if(hasPrivilege("ban")){
        room->removeUser(user);

        cout << "[ADMIN ACTION] " << getName() << " banned " << user->getName()  << " from " << room->getChatRoomName() << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have ban privileges" << endl;
    }
}

/**
 * @brief Delete a message from the chat room history
 * @param room The chat room containing the message
 * @param messageIndex The index of the message to delete
 * 
 * Removes a specific message from the chat history if this admin
 * has the "delete_messages" privilege.
 */
void AdminUser::deleteMessage(ChatRoom* room, int messageIndex){
    if(hasPrivilege("delete_messages")){

        cout << "[ADMIN ACTION] " << getName() << " deleted message " << messageIndex << " from " << room->getChatRoomName() << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have message deletion privileges" << endl;
    }
}