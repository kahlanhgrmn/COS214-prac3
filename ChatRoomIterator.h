/**
 * @file ChatRoomIterator.h
 * @brief ConcreteIterator for the Chatroom collection
 * @author Kahlan Hagerman
 * @date 2025-19-16
 */

#ifndef CHATROOM_ITERATOR_H
#define CHATROOM_ITERATOR_H

#include "Iterator.h"
#include "ChatRoom.h"
#include <vector>
using namespace std;

/**
 * @class ChatRoomIterator
 * @brief ConcreteIterator implementation for traversing the Chatroom collection
 * 
 * This class is used to give iteration capabilities for the collection of Chatrooms that a user belongs to,
 * allowing traversal without needing to know the structure.
 */

class ChatRoomIterator: public Iterator<ChatRoom*>{
    private:
        vector<ChatRoom*> chatRooms;
        int currIndex;

    public:
        explicit ChatRoomIterator(const vector<ChatRoom*>& chatroomCollection);

        bool hasNext() override;

        ChatRoom* next() override;

        void reset() override;

        ChatRoom* current() override;
};

#endif