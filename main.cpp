//
//  main.cpp
//  VectorClass.cpp
//
//  Created by Parth Sunil Songire on 21/08/22.
//

#include <iostream>
#include <string>
#include <vector>

#include "LinkedList.hpp"
#include "stack.hpp"
#include "expr.hpp"
#include "tokenizer.hpp"

using namespace std;

template <typename T>
class Vector
{
private:
    T *arr;
    int currsize;
    int capacity;

public:
    Vector(int n=1)
    {
        arr= new T[n];
        currsize=0;
        capacity=n;
    }

    ~Vector()
    {
        delete []arr;
    }

    int curr_size()
    {
        return currsize;
    }


    T & operator[](int index)
    {
        if(index<currsize)
            return arr[index];

        if(index>currsize)
        {
            cout<<"Error...."<<endl;
            exit(1);
        }

        if(currsize==capacity)
        {
            T *narr = new T[2*capacity];

            for(int i=0;i<capacity;i++)
            {
                narr[i]=arr[i];
            }
            delete []arr;
            arr=narr;
            capacity *=2;
        }

        currsize +=1;
        return arr[index];
    }
};

const int MAX=10000;

template <typename T>
class Stack
{
    int top;
    Vector<T> v;//MAX=10000

public:

    Stack()
    {
        top=-1;
    }

    bool push(T x);
    T pop();
    T peek();
    bool IsEmpty();
};

template <typename T>
bool Stack<T>::push(T x)
{
    if(top>=MAX-1)
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else
    {
        v[++top]=x;
        cout<<x<<" pushed into stack"<<endl;
        return true;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow"<<endl;
        return 0;
    }
    else
    {
        T x = v[top--];
        return x;
    }
}

template <typename T>
T Stack<T>::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        T x = v[top];
        return x;
    }
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return (top < 0);
}

int main()
{
    Tokenizer tokenizer;
    Token *t;
    Stack<Token*> stack;
    Linkedlist<Token*> outls;
    
    while((t=tokenizer.next()))
    {
        if(t->isNum())
        {
            outls.append(t);
            continue;
        }
        if(t->isOper())
        {
            for(;!stack.isEmpty() && stack.top()->isOper() && stack.top->precedence()>t->precedence;outls.append(stack.pop()) );
            stack.push(t);
            continue;
        }
        
        if(t->isLeftBracket())
        {
            stack.push(t);
            continue;
        }
        
        if(t->isRightBracket())
        {
            for(;!stack.top()->isLeftBracket(); outls.append(stack.pop()) );
            stack.pop;
            continue;
        }
    }
    
    for(;!stack.isEmpty() ; outls.append(stack.pop()) );
    
    for(int i=0;i<outls.size();i++)
    {
        cout<<*outls.get(i)<<" ";
    }
    cout<<endl;
    
    Expr *c1 = new Const(5);
    Expr *c2 = new Const(6);
    Expr *p = new Plus(c1,c2);
    Expr *m = new Mult(p, new Const(10));
    cout<< m->eval() <<endl;
    
    return 0;
}
