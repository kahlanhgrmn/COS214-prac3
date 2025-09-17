/**
 * @file MessageHistoryIterator.h
 * @brief ConcreteIterator for the chats message history
 * @author Kahlan Hagerman
 * @date 2025-09-16
*/

#ifndef MESSAGE_HISTORY_ITERATOR_H
#define MESSAGE_HISTORY_ITERATOR_H

#include "Iterator.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @class MessageHistoryIterator
 * @brief ConcreteIterator implements for traversing the message history for the different chats
 * 
 * This class provides iteration capabilities over chat message collections 
*/

class MessageHistoryIterator: public Iterator<std::string>{
    private:
        vector<std::string> messages;
        int currIndex;
        bool reverseOrder;

    public:
        explicit MessageHistoryIterator(const vector<std::string>& messageHist, bool reverse = false);

        bool hasNext() override;

        std::string next() override;

        void reset() override;

        std::string current() override;
};

#endif