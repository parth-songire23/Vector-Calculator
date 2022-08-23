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

//  evaluation function
int eval(int a, int b, char op)
{
    if(op=='+')
        return a+b;
    else if(op=='*')
        return a*b;
    else if(op=='/')
        return b/a;
    else if(op=='-')
        return b-a;
}


int precedence(char a)
{
    if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return 0;
}



int main()
{
//    Stack<char> s;
//    s.push('m');
//    s.push('p');
//    s.peek();

    string s;
    cout<<"please enter the expression"<<endl;
    cin>>s;

    Stack<int> Value;
    Stack<char> Operator;

    for(int i=0;i<s.length();i++)
    {
        if(48<=s[i] && s[i]<=57)
            Value.push(s[i]-48);
        else if(s[i]=='(')
            Operator.push(s[i]);
        else if(s[i]==')')
        {
            while(Operator.peek()!='(')
            {
                char ch=Operator.pop();
                int v1=Value.pop();
                int v2=Value.pop();
                Value.push(eval(v1,v2,ch));
            }
            char waste = Operator.pop();
        }
        else
        {
            if(Operator.IsEmpty())
                Operator.push(s[i]);
            while(!Operator.IsEmpty() && precedence(s[i])<=precedence(Operator.peek()))
            {
                char ch=Operator.pop();
                int v1=Value.pop();
                int v2=Value.pop();
                Value.push(eval(v1,v2,ch));
            }
            char waste = Operator.pop();
        }
    }

    while(!Operator.IsEmpty())
    {
        char ch=Operator.pop();
        int v1=Value.pop();
        int v2=Value.pop();
        Value.push(eval(v1,v2,ch));
    }

    cout<<Value.peek()<<endl;
    return 0;
}












