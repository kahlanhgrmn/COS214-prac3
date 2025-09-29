/**
 * @file Iterator.h
 * @brief Abstract Iterator interface for the Iterator design pattern
 * @author Kahlan Hagerman
 * @date 2025-09-16
 */

#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * @class Iterator
 * @brief Abstract base class for all of the iterators
 * @tparam T The elements to iterate over
 * 
 * This class is used to define the common interface that all concrete iterators must implement.
 * It is used to access elements, and it enables sequential access and traversal.
 */

template<class T>
class Iterator{
    public:
        virtual ~Iterator() = default;

        virtual bool hasNext() = 0;

        virtual T next() = 0;

        virtual void reset() = 0;

        virtual T current() = 0;
};

#endif