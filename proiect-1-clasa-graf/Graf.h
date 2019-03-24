#ifndef GRAF_H
#define GRAF_H
#include "Queue.h"
#include<iostream>
using namespace std;
struct Nod
{
    int data;
    struct Nod* next;

};
struct List
{

    struct Nod *head;
};

class Graf
{

    int V,muchii;
    List* l;
public:
    Graf();
    Graf(int v,int m);
    Graf(Graf& g);
    ~Graf();
    bool isConnected(int,int);
    void addEdge(int src,int dest);
    void print();
    void BFS(int start);
    void DFS(int,int);
    int distanta(int,int);
    bool VerificaCicluri(int v, bool vizitat[]);
    bool isTree();
    void BFSUtil(int,bool*);
    int isConnected2(int);
    friend ostream & operator << (ostream &os,const Graf& g);
    friend istream & operator >> (istream &is, Graf& g);
    Graf&  operator = (const Graf &g);
    int operator<(Graf& g);
    int operator>(Graf& g);
    int getVertex()
    {
        return V;
    }
    int getEdge()
    {
        return muchii;
    }



};


#endif // GRAF_H
