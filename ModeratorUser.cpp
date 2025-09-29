/**
 * @file ModeratorUser.cpp
 * @brief Implementation of the ModeratorUser methods
 * @author Kahlan Hagerman
 * @date 2025-09-28
 */

#include "ModeratorUser.h"
#include "ChatRoom.h"
#include <iostream>

/**
 * @brief Construct a ModeratorUser with a given name
 * @param userName The name for this moderator user
 * 
 * Creates a moderator user with content moderation privileges.
 * Moderators have basic user capabilities plus limited admin functions.
 */
ModeratorUser::ModeratorUser(const string& userName): Users(userName){}

/**
 * @brief Add moderation privileges to this moderator user
 * @param privs Vector of privilege strings to grant to this moderator
 * 
 * Sets the list of moderation privileges that this moderator possesses, 
 * such as mute, warn, and view reports.
 */
void ModeratorUser::addPrivileges(const vector<string>& privs){
    privileges = privs;
}

/**
 * @brief Check if this moderator user has a specific privilege
 * @param privilege The privilege to check for
 * @return true if the moderator has this privilege, false if not
 * 
 * Verifies whether this moderator has been granted the specified
 * privilege for moderation.
 */
bool ModeratorUser::hasPrivilege(const string& privilege)const{
    for(const string& priv: privileges){
        if(priv == privilege){
            return true;
        }
    }

    return false;
}

/**
 * @brief Get the type of this user
 * @return String "Moderator" indicating this user is a moderator
 * 
 * Returns the user type used to distinguish moderators
 * from other user types in the system.
 */
string ModeratorUser::getUserType()const{
    return "Moderator";
}

/**
 * @brief Temporarily mute a user in the specified chat room
 * @param user The user to mute
 * @param room The chat room where the user should be muted
 * 
 * Prevents the specified user from sending messages for a period of time.
 */
void ModeratorUser::muteUser(Users* user, ChatRoom* room){
    if(hasPrivilege("mute")){

        cout << "[MODERATOR ACTION] " << getName() << " muted " << user->getName() << " in " << room->getChatRoomName() << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have mute privileges" << endl;
    }
}

/**
 * @brief Issue a warning to a user
 * @param user The user to warn
 * @param reason The reason for the warning
 * 
 * Sends an official warning to the specified user.
 */
void ModeratorUser::warnUser(Users* user, const string& reason){
    if(hasPrivilege("warn")){

        cout << "[MODERATOR WARNING] " << getName() << " warned " << user->getName() << " - Reason: " << reason << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have warning privileges" << endl;
    }
}

/**
 * @brief View user reports for the specified chat room
 * @param room The chat room to view reports for
 * 
 * Displays user reports and moderation information.
 */
void ModeratorUser::viewUserReports(ChatRoom* room){
    if(hasPrivilege("view_reports")){

        cout << "[MODERATOR INFO] " << getName() << " viewing reports for " << room->getChatRoomName() << endl;
    }
    
    else{
        cout << "[ERROR] " << getName() << " does not have report viewing privileges" << endl;
    }
}