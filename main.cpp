//
//  main.cpp
//  LinkedList.hpp
//
//  Created by Parth Sunil Songire on 06/09/22.
//

#include "LinkedList.hpp"
#include "stack.hpp"
#include "expr.hpp"
#include "tokenizer.hpp"
using namespace std;


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
