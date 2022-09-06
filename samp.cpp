//
//  main.cpp
//  samp.cpp
//
//  Created by Parth Sunil Songire on 06/09/22.
//
#include <iostream>
using namespace std;

template <class T>
class Link
{
public:
    T _data;
    Link *_prev;
    Link *_next;
    Link(const T &data): _data(data) {_prev=_next=NULL;}
    ~Link(){_prev=_next=NULL;}
};
template <class T>
class Linkedlist
{
public:
    Link<T> *_head;
    Link<T> *_tail;
    int _length;
    
    Linkedlist()
    {
        _head=_tail=NULL;
        _length=0;
    }
    
    ~Linkedlist()
    {
        for(int i=0;i<_length;i++)
        {
            Link<T> *n=_head;
            _head=_head->_next;
            delete n;
        }
    }
    
    int size()
    {
        return _length;
    }
    void append(const T &data)
    {
        Link<T> *n =new Link(data);
        if(_length==0)
        {
            _head=_tail=n;
        }
        else
        {
            _tail->_next=n;
            n->_prev=_tail;
            _tail=n;
        }
        _length+=1;
    }
    
    T &tail(){return _tail->_data;}
    
    T remove_last()
    {
        T ret =_tail->_data;
        Link<T> *tail = _tail;
        
        if(_length==1)
            _head=_tail=NULL;
        else
            _tail=_tail->_prev;
        
        delete tail;
        _length -=1;
        return ret;
    }
    
    T &get(int index)
    {
        Link<T> *curr=_head;
        for(int i=0;i<index;i++)
        {
            curr=curr->next;
        }
        return curr->_data;
    }
};

template <class T>
class Stack
{
private:
    Linkedlist<T> _stack;
    
public:
    Stack(){};
    bool isEmpty() { return _stack.size()==0;}
    int size() { return _stack.size();}
    T &top() { return _stack.tail();}
    
    void push(const T &e){_stack.append(e);}
    T pop(){return _stack.remove_last();}
};

template<class T>
class Queue
{
    
private:
    Linkedlist<T> _queue;
    
public:
    Queue(){};
    
    void enQueue(T x)
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
        Link<T> *temp = _queue._head;
        
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
        return _queue._head->_data;
    }
    
    int atrear()
    {
        return _queue._tail->_data;
    }
};

int main()
{
    Queue<int> q;
    q.enQueue(10);
    int t = q.atfront();
    cout<<t<<endl;
    return 0;
}

