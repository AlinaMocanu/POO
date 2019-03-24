#ifndef QUEUE_H
#define QUEUE_H
#include "Graf.h"

class Queue
{
    struct Nod* front;
    struct Nod* rear;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enque(int);
    int deque();
    void display();


};

#endif // QUEUE_H
