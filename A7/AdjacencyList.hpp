#include <iostream>
using namespace std;
#include "GraphAdjacencyBase.hpp"

#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "seqLinearList.hpp"
#include "list.hpp"



class AdjacencyList : public GraphAdjacencyBase {
  
  private:
  	LinearList< list<int> > AdList;
  	int v;
  	int e;

  public:
  
  AdjacencyList()
  {
    v=0;
    e=0;
  }

  LinearList< list<int> > AdjList()
  {
    return AdList;
  }

  void resAdjacencyList(int V);

  ~AdjacencyList();

  bool edgeExists(int i, int j);
	
  int vertices();

  int edges();

  void add(int i, int j);

  void remove(int i, int j);

  void print();

  int indegree(int i);

  int outdegree(int i);
};


void AdjacencyList::resAdjacencyList(int V)
  {
  	AdList.resize(V);
  	v=V;
  	e=0;
  }

AdjacencyList::~AdjacencyList()
  {

  }

  bool AdjacencyList::edgeExists(int i, int j)
  {
  	return AdList[i].find(j);
  }
	
  int AdjacencyList::vertices()
  {
  	return v;
  }

  int AdjacencyList::edges()
  {
  	return e;
  }

  void AdjacencyList::add(int i, int j)
  {
  	
    if(!(this->edgeExists(i,j)))
    {
      AdList[i].append(j);
      e++;
    }
  	//AdList[j].append(i);
  }

  void AdjacencyList::remove(int i, int j)
  {
  	 if(this->edgeExists(i,j))
    {
      AdList[i].remove(j);
      e--;
  	}//AdList[j].remove(i);
  }

  int AdjacencyList::indegree(int i)
  {
      int c=0;
      for(int j=0;j<v;j++)
      {
      if(AdList[j].find(i)) c++;
      }
      return c;
  }

  int AdjacencyList::outdegree(int i)
  {
    return AdList[i].length();  
  }

   void AdjacencyList::print()
  {
  	cout<<endl;
    for(int i=0;i<v;i++)
    	{
    		cout<<i<<" : ";
    		AdList[i].print();
    		cout<<endl;
    	}	
    	cout<<endl;
  }

#endif /* ifndef ADJACENCY_LIST */