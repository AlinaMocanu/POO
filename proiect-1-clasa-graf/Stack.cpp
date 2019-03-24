#include "Stack.h"
#include "Graf.h"
#include<iostream>
using namespace std;
Stack::Stack()
{
  top = NULL;
}
void Stack::push(int x)
{
    Nod* p=new Nod;
    p->data = x;
    p->next = NULL;
    if(top!=NULL)
    {
        p->next = top;
    }
    top = p;
}
int Stack::pop()
{
    Nod* temp;
    int value;
    if(top==NULL){
        cout<<"\nStiva e vida!"<<endl;
    }
    else
    {
        temp = top;
        top = top->next;
        value = temp->data;
        delete temp;
    }
    return value;
}
bool Stack::isEmpty()
{
    return (top == NULL);
}
void Stack::display()
{
    Nod* p = top;
    if(top==NULL){
        cout<<"\nStiva vida\n";
    }
    else
    {
        cout<<"\nContinutul stivei:\n";
        while(p!=NULL){
            cout<<p->data<<endl;
            p = p->next;
        }
    }
}
Stack::~Stack()
{
  delete top;
}
