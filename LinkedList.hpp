//
//  LinkedList.hpp
//  LinkedList.hpp
//
//  Created by Parth Sunil Songire on 06/09/22.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
using namespace std;
template <class T>
class Linkedlist
{
private:
    class Link
    {
    public:
        T _data;
        Link *_prev;
        Link *_next;
        Link(const T &data): _data(data) {_prev=_next=NULL;}
        ~Link(){_prev=_next=NULL;}
    };

    Link *_head;
    Link *_tail;
    int _length;

public:
    Linkedlist()
    {
        _head=_tail=NULL;
        _length=0;
    }

    ~Linkedlist()
    {
        for(int i=0;i<_length;i++)
        {
            Link *n=_head;
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
        Link *n =new Link(data);
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

    T &tail()
    {
        if(_tail==NULL)
            cout<<"No elements left... :("<<endl;
        return _tail->_data;
    }
    T &head()
    {
        if(_head==NULL)
            cout<<"No elements left... :("<<endl;
        return _head->_data;
    }

    T remove_last()
    {
        T ret =_tail->_data;
        Link *tail = _tail;

        if(_length==1)
            _head=_tail=NULL;
        else
            _tail=_tail->_prev;

        delete tail;
        _length -=1;
        return ret;
    }

    T remove_start()
    {
        if(_head==NULL)
            return 0;
        T ret = _head->_data;
        Link *head=_head;

         if(_length==1)
            _head=_tail=NULL;
        else
            _head=_head->_next;

        delete head;
        _length -=1;
        cout<<ret<<" deQueued"<<endl;
        return ret;

    }

    T &get(int index)
    {
        Link *curr=_head;
        for(int i=0;i<index;i++)
        {
            curr=curr->next;
        }
        return curr->_data;
    }
};

#endif /* LinkedList_h */
