#include "Graf.h"
#include "Queue.h"
#include "Stack.h"
#include<iostream>
using namespace std;

Graf::Graf()
{
    V=0;
    muchii=0;
    l=NULL;
}
Graf::Graf(int v,int m)
{
    int a,b;
    V=v;
    muchii=m;
    l=new  List[V+1];
    for (int i = 1; i <=V; i++)
        l[i].head=NULL;
}
Graf::Graf(Graf& g)
{
    Nod *temp,*temp2;

    this->V=g.V;
    this->muchii=g.muchii;
    l=new List[V+1];
    for(int i=1; i<=V; i++)
        l[i].head=g.l[i].head;
    for(int i=1; i<=V; i++)
    {
        temp2=g.l[i].head;

        while(temp2!=NULL)
        {
            temp=new Nod;
            temp->data=temp2->data;
            temp->next=NULL;
            temp=temp->next;
            temp2=temp2->next;
        }
    }




}
Graf::~Graf()
{
    Nod* temp;
    Nod* next;
    for(int i=1; i<=V; i++)
    {
        temp=l[i].head;
        while(temp!=NULL)
        {
            next=temp->next;
            delete temp;
            temp=next;
        }

    }
    for(int i=1; i<=V; i++)
        delete l[i].head;
}
void  Graf::addEdge(int src,int dest)
{

    Nod* newNod= new Nod;
    newNod->data=dest;
    newNod->next=NULL;

    newNod->next = l[src].head;
    l[src].head = newNod;

    newNod = new Nod;
    newNod->data = src;
    newNod->next = NULL;

    newNod->next = l[dest].head;
    l[dest].head = newNod;



}
///verifica daca doua noduri sunt adiacente
///parcurge lista de adiacenta a nodului u cautandu-l pe v

bool Graf::isConnected(int u, int v)
{
    Nod* temp;
    temp=l[u].head;

    while(temp!=NULL)
    {
        if(temp->data==v)
            return true;
        temp=temp->next;
    }
    return false;


}
void Graf::print()
{
    cout<<"Numar noduri "<<V;
    cout<<endl<<"Numar muchii "<<muchii<<endl;
    for (int v = 1; v <= V; v++)

    {
        Nod* temp = l[v].head;
        cout<<"\n Lista de adiacenta a nodului "<<v<<"\n head ";
        while (temp)
        {
            cout<<"-> "<<temp->data;
            temp = temp->next;
        }
        cout<<endl;
    }

}

void Graf::BFS(int start)
{

    Queue Q;

    bool *vizitat=new bool[V+1];
    for(int i=1; i <= V; i++)
        vizitat[i]=false;

    Q.enque(start);
    vizitat[start]=true;
    cout << "BFS incepand din nodul  ";
    cout << start << " : " << endl;

    while(!Q.isEmpty())
    {
        int v=Q.deque();
        cout<<v<<" ";

        for (int w = 1; w <= V; w++)
            if (isConnected(v, w) && !vizitat[w])
            {
                Q.enque(w);
                vizitat[w] = true;
            }
    }
    cout << endl;
    delete [] vizitat;

}
void Graf::DFS(int x, int required)
{
    Stack s;

    bool *vizitat = new bool[V+1];
    for(int i = 0; i <= V; i++)
        vizitat[i] = false;

    s.push(x);
    vizitat[x] = true;

    if(x == required)
        return;
    cout << " DFS din nodul ";
    cout <<  x << " : " << endl;

    while(!s.isEmpty())
    {
        int k = s.pop();
        if(k == required)
            break;
        cout<<k<<" ";
        for (int i = V; i >= 0 ; --i)
            if (isConnected(k, i) && !vizitat[i])
            {
                s.push(i);
                vizitat[i] = true;
            }
    }
    cout<<endl;
    delete [] vizitat;
}
///returneaza distanta dintre doua noduri
///pornind de la BFS ,metoda contine si un vector de distante care e initializat cu 0
///distanta unui nod este modificata atunci cand acesta e nevizitat si adiacent cu nodul a carui lista este parcursa

int Graf::distanta(int u,int t)
{
    int* distance=new int[V+1];
    for(int i=1; i <= V; i++)
        distance[i]=0;

    bool *vizitat = new bool[V+1];
    for (int i = 1; i <= V; i++)
        vizitat[i] = false;

    Queue Q;
    Q.enque(u);
    vizitat[u]=true;

    while(!Q.isEmpty())
    {
        int v=Q.deque();

        for (int w = 1; w <= V; w++)

            if (isConnected(v, w) && !vizitat[w])
            {
                Q.enque(w);
                vizitat[w] = true;
                distance[w]=distance[v]+1;

            }

    }
    delete [] vizitat;
    return distance[t];
}

///Metoda verifica daca exista cicluri in graf
/// pentru orice nod v vizitat daca gasim un nod adiacent u care este vizitat si nu este parinte pentru v,atunci graful este ciclic
bool Graf::VerificaCicluri(int v, bool vizitat[])
{
    int *parent=new int[V+1];
    for (int i = 1; i <= V; i++)
        parent[i] = -1;
    Queue Q;
    Q.enque(v);
    vizitat[v] = true;

    while(!Q.isEmpty())
    {
        int x=Q.deque();

        for (int w = 1; w <= V; w++)
            if (isConnected(x, w) && !vizitat[w])
            {
                Q.enque(w);
                vizitat[w] = true;
                parent[w]=x;
            }
            else if (w != parent[x] && isConnected(x, w) )

                return true;

    }
    delete [] parent;
    return false;
}
///daca functia anterioara intoarce true (exista cicluri)
///sau daca mai exista o valoare false in vectorul vizitat atunci graful nu e arbore(graf neconex)
bool Graf::isTree()
{

    bool *vizitat = new bool[V+1];

    for (int i = 1; i <= V; i++)
        vizitat[i] = false;


    if (VerificaCicluri(1, vizitat))
        return false;

    for (int u = 1; u <= V; u++)
        if (!vizitat[u])
        {
            delete [] vizitat;
            return false;
        }
    delete [] vizitat;
    return true;
}
///BFS cu doi parametri ce ajuta la identificarea numarului de componente conexe
void Graf::BFSUtil(int start,bool vizitat[])
{
    Queue Q;
    Q.enque(start);
    vizitat[start]=true;

    while(!Q.isEmpty())
    {
        int v=Q.deque();

        for (int w = 1; w <= V; w++)
            if (isConnected(v, w) && !vizitat[w])
            {
                Q.enque(w);
                vizitat[w] = true;


            }
    }
}
///determina numarul de componente conexe
int Graf::isConnected2(int start)
{
    int k=0;

    bool *vizitat=new bool[V+1];
    for(int i=1; i<=V; i++)
        vizitat[i]=false;
    for (int v=1; v<=V; v++)
    {
        if (vizitat[v] == false)
        {

            BFSUtil(v, vizitat);
            k++;
        }
    }
    delete []vizitat;
    return k;
}

///supraincarcare >>
istream & operator >> (istream &is, Graf& g)
{
    int a,b;
    is>>g.V;
    is>>g.muchii;
    Nod* temp;
    g.l=new  List[g.V+1];
    for (int i = 1; i <= g.V; i++)
        g.l[i].head = NULL;

    for(int i=1; i<=g.muchii; i++)
    {
        is>>a>>b;
        g.addEdge(a,b);
    }
    return is;
}


///supraincarcare <<
ostream & operator << (ostream &os,const Graf& g)
{
    os<<"Numar noduri:";
    os<<g.V<<endl;
    os<<"Numar muchii :";
    os<<g.muchii<<endl;
    Nod* temp;
    os<<"listele de adiacenta:"<<endl;
    for(int i=1; i<=g.V; i++)
    {
        temp=g.l[i].head;
        os<<"nodul "<<i<<" : ";
        while(temp!=NULL)
        {
            os<<temp->data<<" ";
            temp=temp->next;
        }
        os<<endl;
    }
    return os;
}
///supraincarcare =
Graf& Graf::operator = (const Graf &g)
{

    Nod *temp,*temp2;
    // Check for self assignment
    if(this != &g)
    {
        this->V=g.V;
        this->muchii=g.muchii;
        l=new List[V+1];
        for(int i=1; i<=V; i++)
            l[i].head=g.l[i].head;;
        for(int i=1; i<=V; i++)
        {
            temp2=g.l[i].head;

            while(temp2!=NULL)
            {
                temp=new Nod;
                temp->data=temp2->data;
                temp->next=NULL;
                temp=temp->next;
                temp2=temp2->next;



            }
        }

    }

    return *this;
}



///supraincarcare > si <
int Graf::operator<(Graf& g)
{
    if(V<g.V || (V==g.V && muchii<g.muchii))
        return 1;
    return 0;


}
int Graf::operator>(Graf& g)
{

    if(V>g.V ||( V==g.V && muchii>g.muchii))
        return 1;
    return 0;


}

