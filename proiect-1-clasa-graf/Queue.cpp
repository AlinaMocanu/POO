#include "Queue.h"
#include "Graf.h"
#include<iostream>
using namespace std;
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    delete front;
}
bool Queue::isEmpty()
{
    return (front==NULL);
}
void Queue::enque(int x)
{
    Nod* temp= new Nod();
    temp->data=x;
    temp->next=NULL;

    if(front == NULL)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}
int Queue::deque()
{
    Nod* temp=new Nod();
    int value;
    if(isEmpty())
        cout<<"\nCoada goala\n";
    else
    {

        temp=front;
        value=temp->data;
        front=front->next;
        delete temp;
    }
    return value;
}
void Queue::display()
{
    Nod* p=new Nod;
    p=front;
    if(isEmpty())
        cout<<"\nCoada goala\n";
    else

        while(p!=NULL)
        {
            cout<<endl<<p->data;
            p = p->next;
        }


}
