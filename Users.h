/**
 * @file Users.h
 * @brief Declares the Users class for chat room participants.
 * @author Gabriela
 * @date 2025-09-16
 */

#ifndef USERS_H
#define USERS_H

class ChatRoom;

 #include "Command.h"
 #include <string>
 #include <vector>
 #include <list>
 using namespace std;

 /**
 * @class Users
* @brief Represents a user in the PetSpace chat system.
 *
 * The Users class acts as both a colleague in the Mediator pattern and
 * an invoker in the Command pattern. Users can join multiple chat rooms,
 * send messages, and receive messages through the mediator.
 */
class Users {
    protected:
        vector<ChatRoom*> chatRooms; //mediator
        string name; 
        list<Command*> commandQueue;
        
    public:
        /**
         * @brief Constructs a user with a given name.
         * @param n The name of the user.
         */
        Users(const string& userName) : name(userName) {}
         
        /**
         * @brief Virtual destructor for Users.
         */
        virtual ~Users() {}

        virtual void send(string message, ChatRoom* room);
        virtual void receive(string message, Users* fromUser, ChatRoom* room);
        virtual void addCommand(Command* command);
        virtual void executeAll();

        //additional functions
        virtual std::string getUserType() const = 0;
        virtual bool hasPrivilege(const std::string&)const {return false;}

        /**
         * @brief Gets the list of chat rooms the user belongs to.
         * @return Vector of pointers to ChatRoom objects.
         */
        const std::vector<ChatRoom*>& getChatRooms() const {return chatRooms;}
        
        /**
         * @brief Gets the user's name.
         * @return The user's name as a string.
         */
        const string& getName() const { return name; }

};

#endif