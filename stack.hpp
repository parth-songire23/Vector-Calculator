//
//  stack.hpp
//  LinkedList.hpp
//
//  Created by Parth Sunil Songire on 06/09/22.
//

#ifndef stack_h
#define stack_h

#include "LinkedList.hpp"


template <class T>
class Stack
{
private:
    Linkedlist<T> _stack;
    
public:
    Stack(){}
    bool isEmpty() { return _stack.size()==0;}
    int size() { return _stack.size();}
    T &top() { return _stack.tail();}
    
    void push(const T &e){_stack.append(e);}
    T pop(){return _stack.remove_last();}
};

#endif /* stack_h */
