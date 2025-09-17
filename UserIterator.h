/**
 * @file UserIterator.h
 * @brief ConcreteIterator for the Users collection
 * @author Kahlan Hagerman
 * @date 2025-19-16
 */

#ifndef USER_ITERATOR_H
#define USER_ITERATOR_H

#include "Iterator.h"
#include "Users.h"
#include <vector>
using namespace std;

/**
 * @class UserIterator
 * @brief ConcreteIterator implementation for traversing the Users collection
 * 
 * This class is used to give iteration capabilities for the collection of Users, allowing for easy
 * traversal without needing to know the underlying structure.
*/

class UserIterator: public Iterator<Users*>{
    private:
        vector<Users*> users;
        int currIndex;

    public:
        explicit UserIterator(const vector<Users*>& userCollection);

        bool hasNext() override;
        
        Users* next() override;

        void reset() override;

        Users* current() override;
};

#endif