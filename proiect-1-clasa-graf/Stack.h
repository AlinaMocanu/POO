#ifndef STACK_H
#define STACK_H
#include "Graf.h"

class Stack
{
    Nod* top;
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    void display();



};

#endif // STACK_H
