/**
 * @file IteratorCreator.cpp
 * @brief Implementation of IteratorCreator methods
 * @author Kahlan Hagerman
 * @date 2025-09-17
 */

#include "IteratorCreator.h"

/**
 * @brief Creates an iterator for users in the chat room
 * @param chatRoom Pointer to the different ChatRoom objects
 * @return Iterator used to go through users in a chat room
 * 
 * Create a UserIterator that allows you to go through the users currently in a chat room
 * without needing to know the internal structure. The caller must then delete the iterator
 * that is returned when finished.
 */
Iterator<Users*>* IteratorCreator::createUserIterator(ChatRoom* chatRoom){
    return new UserIterator(chatRoom->getUsers());
}

/**
 * @brief Creates an iterator for message history in the chat room
 * @param chatRoom Pointer to the different ChatRoom objects
 * @param reverseOrder If true then iterate from the newest to the oldest messages
 * @return Iterator used to go through message history in a chat room
 * 
 * Create a MessageHistoryIterator that allows you to go through the chat history in either
 * chronological or reverse chronological order. The caller must then delete the iterator
 * that was returned when finished.
 */
Iterator<std::string>* IteratorCreator::createMessageIterator(ChatRoom* chatRoom, bool reverseOrder){
    return new MessageHistoryIterator(chatRoom->getChatHistory(), reverseOrder);
}

/**
 * @brief Creates an iterator for chat rooms the user is in
 * @param user Pointer to the Users object
 * @return Iterator used to go through chat rooms
 * 
 * Create a ChatRoomIterator that allows you to go through all chat rooms that the given user 
 * is a part of. Users can belong to multiple chat rooms, so you can see which they are in.
 * The caller must then delete the iterator that was returned when finished.
 */
Iterator<ChatRoom*>* IteratorCreator::createChatRoomIterator(Users* user){
    return new ChatRoomIterator(user->getChatRooms());
}