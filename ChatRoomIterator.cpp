/**
 * @file ChatRoomIterator.cpp
 * @brief Implementation of the ChatRoomIterator class methods
 * @author Kahlan Hagerman
 * @date 2025-09-16
 */

#include "ChatRoomIterator.h"
#include <iostream>

/**
 * @brief Construct a ChatRoomIterator
 * @param chatroomCollection The collection of different chat rooms to iterate over
 * 
 * Create a copy of the chat room collection for safe iteration and sets the current 
 * index to the beginning of the collection. The iterator will therefore not be affected
 * by changes in the original collection while iterating.
 */
ChatRoomIterator::ChatRoomIterator(const vector<ChatRoom*>& chatroomCollection): chatRooms(chatroomCollection), currIndex(0){}

/**
 * @brief Checks if there are any more chat rooms to iterate over
 * @return true if there are more rooms, false if not
 * 
 * Check that the current index is in a valid range in the collection. This is then used to
 * prevent accessing elements that are not in the collection bounds.
 */
bool ChatRoomIterator::hasNext(){
    return currIndex < chatRooms.size();
}

/**
 * @brief Gets the next chat room and moves the iterator one forward
 * @return Pointer to the next object in the collection
 * 
 * Get the chat room at the current position and then moves the iterator. This will then
 * move the iterator to the next element in the collection. Return nullptr if no more
 * rooms are in the collection.
 */
ChatRoom* ChatRoomIterator::next(){
    if(!hasNext()){
        return nullptr;
    }

    return chatRooms[currIndex++];
}

/**
 * @brief Resets iterator to the beginning of the collection
 * 
 * Used to set the current index back to 0 to be able to go through the same 
 * chat room collection multiple times. 
 */
void ChatRoomIterator::reset(){
    currIndex = 0;
}

/**
 * @brief Gets the current chat room without moving the iterator forward
 * @return Pointer to the current object in the collection
 * 
 * Returns the chat room at the current position without moving the iterator. This then
 * allows for looking at the current element multiple times. Returns nullptr if the 
 * iterator is at the end of the collection.
 */
ChatRoom* ChatRoomIterator::current(){
    if(currIndex >= chatRooms.size()){
        return nullptr;
    }

    return chatRooms[currIndex];
}