//
//  Queue.hpp
//  LinkedList.hpp
//
//  Created by Parth Sunil Songire on 06/09/22.
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.hpp"

template<class T>
class Queue
{

private:
    Linkedlist<T> _queue;

public:
    Queue(){};

    void enQueue(int x)
    {
        _queue.append(x);
    }

    void deQueue()
    {
        _queue.remove_start();
    }

    int atfront()
    {
        return _queue.head();
    }

    int atrear()
    {
        return _queue.tail();
    }
};

#endif /* Queue_h */
