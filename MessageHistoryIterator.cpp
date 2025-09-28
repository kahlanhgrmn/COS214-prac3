/**
 * @file MessageHistoryIterator.cpp
 * @brief Implementation of the MessageHistoryIterator class methods
 * @author Kahlan Hagerman
 * @date 2025-09-16
 */

#include "MessageHistoryIterator.h"
#include <iostream>

/**
 * @brief Construct a MessageHistoryIterator
 * @param messageHist The messages collection to iterate over
 * @param reverse If true, iterate from the newest to oldest messages
 * 
 * Create copy of the message history and then sets the starting position depending on if you want
 * to traverse from the front or the back.
 * Forward will start at 0, and reverse will start at the last message.
 */

MessageHistoryIterator::MessageHistoryIterator(const vector<std::string>& messageHist, bool reverse): messages(messageHist), reverseOrder(reverse){
    if(reverseOrder){
        currIndex = messages.size() - 1;
    }

    else{
        currIndex = 0;
    }
}

/**
 * @brief Checks if there are more messages to iterate over
 * @return true if there are more messages, false if not
 * 
 * Checks bounds differently based on the direction of iteration. For forward iteration, it will 
 * check if the index is less than size. For reverse iteration it will check is the
 * index is greater than or equal to 0.
 */

bool MessageHistoryIterator::hasNext(){
    if(reverseOrder){
        return currIndex >= 0;
    }

    else{
        return currIndex < messages.size();
    }

}

/**
 * @brief Gets the next message and then moves the iterator forward
 * @return The next message string
 * 
 * Returns the message that is at the current position and then moves the iterator. The direction
 * of the movement will depend on the reverseOrder variable.
 * Forward will increment the index and reverse will decrement the index.
 * Will return the empty string if there are no more messages.
 */

std::string MessageHistoryIterator::next(){
    if(!hasNext()){
        return "";
    }

    if(reverseOrder){
        return messages[currIndex--];
    }

    else{
        return messages[currIndex++];
    }
}

/**
 * @brief Reset the iterator to the beginning again
 * 
 * Reset the current index to the start position based on the direction of iteration, forward is 0
 * and reverse is size - 1. This allows the iterator to be used for multiple passes over the collection.
 */

void MessageHistoryIterator::reset(){
    if(reverseOrder){
        currIndex = messages.size() - 1;
    }

    else{
        currIndex = 0;
    }
}

/**
 * @brief Gets the current message without moving the iterator forward
 * @return The current message string
 * 
 * Returns the message that is at the current position without moving the iterator position.
 * It is used to when you want to look at the current element multiple times. Returns the empty
 * string if the iterator is at the end of the collection.
 */

std::string MessageHistoryIterator::current(){
    if(reverseOrder && (currIndex < 0)){
        return "";
    }

    if(!reverseOrder && (currIndex >= messages.size())){
        return "";
    }

    return messages[currIndex];
}