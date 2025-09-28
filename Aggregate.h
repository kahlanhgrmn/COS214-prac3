/**
 * @file Aggregate.h
 * @brief Abstract Aggregate interface for collections that can be iterated through
 * @author Kahlan Hagerman
 * @date 2025-09-16
*/

#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"

/**
 * @class Aggregate
 * @brief Abstract base class for collections that're able to make iterators
 * @tparam T The type of elements in the collections
 * 
 * This interface is used to ensure that collections can provide iterators
 * for traversal without needing to know the structure.
*/

template<class T>
class Aggregate{
    public:
        virtual ~Aggregate() = default;

        virtual Iterator<T*> createIterator() = 0;

        virtual int size() const = 0;

        virtual bool isEmpty() const = 0;
};

#endif