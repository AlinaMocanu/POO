#include <iostream>
#include "Graf.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main()
{
    Graf g1(5,4),g2,g3;
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(1,4);
    g1.addEdge(4,5);

    g1.BFS(2);
    g1.DFS(2,6);
    g1.print();
    cout<<g1.distanta(2,5)<<endl;
    g1.isTree()? cout << "Graph is Tree\n":
                      cout << "Graph is not Tree\n";
    cout<<g1.isConnected2(1)<<endl;
    cout<<g1.getVertex()<<" "<<g1.getEdge()<<endl;
    /*cin>>g2;
    cout<<g2<<endl;
    if(g1>g2)
        cout<<"g1>g2";
    else if(g1<g2)
        cout<<"g1<g2";*/
    g3=g1;
    cout<<g3;


    return 0;
}
