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
    // If queue is empty, return NULL.
        if (_queue._head == NULL)
            return;
      
    // Store previous front and
    // move front one node ahead
        Link *temp = _queue._head;
        
    //  QNode* temp = front;
        _queue._head = _queue._head->next;
      
    // If front becomes NULL, then
    // change rear also as NULL
        if (_queue._head == NULL)
            _queue._tail = NULL;
      
        delete (temp);
    }

    int atfront()
    {
        return _queue._head->data;
    }
    
    int atrear()
    {
        return _queue._tail->data;
    }
};

#endif /* Queue_h */
