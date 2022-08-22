//
//  main.cpp
//  VectorClass.cpp
//
//  Created by Parth Sunil Songire on 21/08/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vector
{
private:
    int *arr;
    int currsize;
    int capacity;
    
public:
    Vector(int n=1)
    {
        arr= new int[n];
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
    
    int & operator[](int index)
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
            int *narr = new int[2*capacity];
            
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
class Stack
{
    int top;
    
public:
    
    int A[MAX];//MAX=10000
    
    Stack()
    {
        top=-1;
    }
    
    bool push(int x);
    int pop();
    int peek();
    bool IsEmpty();
};

bool Stack::push(int x)
{
    if(top>=MAX-1)
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else
    {
        A[++top]=x;
        cout<<x<<" pushed into stack"<<endl;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = A[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = A[top];
        return x;
    }
}
  
bool Stack::IsEmpty()
{
    return (top < 0);
}

int main()
{
    
    
    
    
    
    
    
    return 0;
}
