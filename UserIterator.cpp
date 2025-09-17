/**
 * @file UserIterator.cpp
 * @brief Implementation of the UserIterator class methods
 * @author Kahlan Hagerman
 * @date 2025-09-16
 */

#include "UserIterator.h"
#include <iostream>

/**
 * @brief Constructs a UserIterator with a collection of users
 * @param userCollection The collection to be iterated over
 * 
 * Creates a copy of the users collection for safe iteration, so that it is safe even if the
 * original gets modified while iterating.
 * It initialises the current index to 0 to start at the begining.
 */

UserIterator::UserIterator(const vector<Users*>& userCollection): users(userCollection), currIndex(0){}

/**
 * @brief Checks if there are any more users in the collection to iterate over
 * @return true if there are more users, false if not
 * 
 * Checks if the current index is within the bounds of the collection, and checks if there are
 * more elements available to iterate over. Used to prevent going past the last user in the collection.
 */

bool UserIterator::hasNext(){
    return currIndex < users.size();
}

/**
 * @brief Gets the next user and moves the iterator forward
 * @return Pointer to the next Users object in the collection
 * 
 * Gets the user that's at the current position and then moves the iterator to the next position.
 * This will then advance the iterator. It returns nullptr if there are no more users.
 */

Users* UserIterator::next(){
    if(!hasNext()){
        return nullptr;
    }

    return users[currIndex++];
}

/**
 * @brief Resets the iterator to the beginning
 * 
 * Set the current index back to 0 so the iterator can move through the collection from
 * the start again. Used for many passes through the same data or collection.
 */

void UserIterator::reset(){
    currIndex = 0;
}

/**
 * @brief Gets current user without moving the iterator
 * @return Pointer to the current Users object
 * 
 * Return the user at the current position of the iterator without moving it forward, this is
 * used to be able to look at the current element multiple times.
 * Return nullptr if the iterator is at the end.
 */

Users* UserIterator::current(){
    if(currIndex >= users.size()){
        return nullptr;
    }

    return users[currIndex];
}