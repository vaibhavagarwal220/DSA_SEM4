#include <iostream>
#include "MinPriorityQueue.hpp"
#include "seqLinearList.hpp"
#include "pair.hpp"
#include "UndirectedGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "DirectedGraph.hpp"
#include "AdjacencyList.hpp"
#include "dsu.hpp"
#include "tuple.hpp"
#include <fstream>
using namespace std;
void work(int &i)
{
	cout<<" "<<i<<" ";
}
int main()
{
	int n,choice;
	tuple temp;
     MinPriorityQueue<tuple> q;
	cout<<"Enter number nodes of graph\n";
	cin>>n;
	string path;
	UndirectedGraph graph(n,'l');
	cout<<"press 1 if input from file or 0 to take from terminal\n";
	cin>>choice;

	if(choice == 1)
	{
		cout<<"enter path\n";
		cin>>path;
		ifstream infile;
		infile.open(path.c_str());
		int data;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{	infile>>data;
				if(data != 0 & i < j)
				{
					graph.add(i,j,data);
					temp.set_parameters(data,i,j);
       				q.insert(temp);
				}
			}
		}
		
	}
	int src,dest,wt,cost=0;
		while(1)
		{
			cout<<"[1]Add edge\n";
			cout<<"[2]Bfs.\n";
			cout<<"[3]Dfs\n";
			cout<<"[4]Kruskal\n";
			cout<<"[5]Prim\n";
			cout<<"[6]Vertices\n";
			cout<<"[7]Edges\n";
			cout<<"[8]Degree\n";
			cout<<"[9]Exit\n";
			cout<<"\nEnter your choice:";
			cin>>choice;

			string key,value;
			switch(choice)
			{
			case 1:
				cout<<"Enter the src: ";
				cin>>src;
				cout<<"Enter the dest : ";
				cin>>dest;
				cout<<"Enter the weight : ";
				cin>>wt;
				graph.add(src,dest,wt);
				temp.set_parameters(wt,src,dest);
       			q.insert(temp);
			break;
			case 2:
			cout<<"Enter source:  ";
				cin>>src;
				graph.bfs(work,src);
				cout<<"\n";
			break;
			case 3:
				cout<<"Enter source:  ";
				cin>>src;
				graph.dfs(work,src);
				cout<<"\n";
			break;

			case 4:
				cout<<"Enter source:  ";
				cin>>src;
				cout<<"Graph edges";
				cost=graph.kruskal(q,n);
				cout<<"Minimum cost: "<<cost<<endl;
				break;
			case 5:
				cout<<"Enter source:  ";
				cin>>src;
				cost=graph.prim(src);
				cout<<"Minumum cost: ";
				cout<<cost<<endl;
				break;
			case 6:
				cout<<graph.vertices()<<endl;
				break;
			case 7:
				cout<<"edges = "<<graph.edges()<<endl;
				break;

			case 8:
				cout<<"Enter src\nDegree: ";
				cin>>src;
				cout<<graph.degree(src)<<endl;
				break;
				case 9:
				cout<<"Exiting\n";
				return 0;
			default:
				cout<<"Invalid input\nTry again\n";
			}

		}
	

	return 0;
}