#include <iostream>
#include "MinPriorityQueue.hpp"
#include "seqLinearList.hpp"
#include "dsu.hpp"
#include "tuple.hpp"
#include "seqLinearList.hpp"
#include "UndirectedGraph.hpp"
#include "AbstractGraph.hpp"
#include "DirectedGraph.hpp"
#include "AdjacencyList.hpp"
int main()
{
	int t;
	cout<<"Number of Test Cases\n";
	cin>>t;
	while(t--)
	{
	int nodes,edges,x,y,weight,minimum_cost=0,queries,ct=0;
     tuple temp;
     MinPriorityQueue<tuple> q;
     cout<<"Enter number of stations\n";
     cin>>nodes;
     cout<<"Enter number of routes\n";
     cin>>edges;
     UndirectedGraph g(nodes,'l');
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter vertex X\n";
        cin>>x;
        cout<<"Enter vertex Y\n";
        cin>>y;
        cout<<"Enter Weight\n";
        cin>>weight;
        temp.set_parameters(weight,x,y);
        //tup.push_back(temp);
        q.insert(temp);
    }
//    // q.print();
 minimum_cost=g.kruskal(q,nodes);
 cout<<"Enter number of queries\n";
cin>>queries;
for(int i=0;i<queries;i++)
{
	int a,b;
	cout<<"Enter start and end vertex\n";
	cin>>a>>b;
	for(int i=0;i<g.src.size();i++)
	{
		if((g.src[i]==a&&g.dest[i]==b)||(g.src[i]==b&&g.dest[i]==a))
			ct++;
	}
}
cout<<"He said YES "<<ct<<" times\n";
}
}
