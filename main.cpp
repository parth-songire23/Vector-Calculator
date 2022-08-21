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


class Stack
{
    Vector v;
    int currsize;
    
    
    
    
};

int main()
{
    
    
    
    
    
    
    
    return 0;
}
