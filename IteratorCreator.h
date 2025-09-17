/**
 * @file IteratorCreator.h
 * @brief Factory class for creating different types of iterators
 * @author Kahlan Hagerman
 * @date 2025-09-16
 */

#ifndef ITERATOR_CREATOR_H
#define ITERATOR_CREATOR_H

#include "UserIterator.h"
#include "MessageHistoryIterator.h"
#include "ChatRoomIterator.h"
#include "ChatRoom.h"
#include "Users.h"

/**
 * @class IteratorCreator
 * @brief Factory class that creates types of iterators for the system
 * 
 * This class provides static methods to create iterators for different collections
 * in the system without exposing the complexity of iterator.
 */

class IteratorCreator{
    public:
        static Iterator<Users*>* createUserIterator(ChatRoom* chatRoom);

        static Iterator<std::string>* createMessageIterator(ChatRoom* chatRoom, bool reverseOrder = false);

        static Iterator<ChatRoom*>* createChatRoomIterator(Users* user);
};

#endif