/**
 * @file Users.h
 * @brief Declares the Users class for managing user actions.
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef USERS_H
#define USERS_H

 #include "ChatRoom.h"
 #include "Command.h"
 #include <string>
 #include <vector>
 #include <list>
 using namespace std;

 /**
 * @class Users
 * @brief Represents a User. Is the invoker 
 *
 *
 */
class Users {
    protected:
        vector<ChatRoom*> chatRooms; //mediator
        string name; 
        list<Command*> commandQueue;
        
    public:
        void send(string message, ChatRoom* room);
        void receive(string message, Users* fromUser, ChatRoom* room);
        void addCommand(Command command);
        void executeAll();

        //additional functions
        const string& getName() const { return name; }

};

#endif