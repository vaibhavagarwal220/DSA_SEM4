#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include <string>
using namespace std;
//using namespace cs202;
 #include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "seqLinearList.hpp"
#include "MinPriorityQueue.hpp"
#include "seqLinearList.hpp"
#include "dsu.hpp"
#include "tuple.hpp"
class UndirectedGraph :public AbstractGraph {
 private:
 public:
     int vertice;
     twin p;
     GraphAdjacencyBase *adjacency;
     LinearList<int> src,dest;
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  /*VIRTUAL FUNCTIONS*/

  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool edgeExits(int i, int j);
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  int edges();
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  int vertices();
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  void add(int i, int j,int weight);
  // void addtwin(int i,twin p)
  // {
  //   adjacency->addtwin(i,p);
  // }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  void remove(int i, int j);
  long long prim(int x)
  {
      adjacency->prim(x);
  }
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void dfs(void (*work)(int&),int src);
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void bfs(void (*work)(int&),int src);

  void print()
  {
     adjacency->print();
  }

  UndirectedGraph(int vertices, char mode);
  /*
   * Returns the degree of the vertex.
   */
  int degree(int i);
 long long int kruskal(MinPriorityQueue<tuple> q,int nodes);
};

UndirectedGraph::UndirectedGraph(int vertices, char mode)
{
     vertice=vertices;
     if(mode=='m')
     {
          // AdjacencyMatrix am(vertices);
          adjacency = new AdjacencyMatrix(vertice);
     }
      else if(mode=='l')
      {
           // AdjacencyList al;
            adjacency=new AdjacencyList(vertice);
      }

}

bool UndirectedGraph::edgeExits(int i, int j)
{
     adjacency->edgeExits(i,j);
}

int UndirectedGraph::edges()
{
    return (adjacency->edges())/2;
}

int UndirectedGraph::vertices()
{
     // cout<<"---vertice : "<<vertice<<endl;
      return adjacency->vertices();
}

void UndirectedGraph::add(int i, int j,int weight)
{
     // (this->adjacency)->add(i,j);
     // cout<<"again\n";
        p.set_parameters(weight,j);
        adjacency->addtwin(i,p);
        p.set_parameters(weight,i);
        adjacency->addtwin(j,p);
}

void UndirectedGraph::remove(int i, int j)
{
     adjacency->remove(i,j);
     adjacency->remove(j,i);
}

void UndirectedGraph::dfs(void (*work)(int&),int src)
{
     adjacency->dfs(work,src);
}

void UndirectedGraph::bfs(void (*work)(int&),int src)
{
    adjacency->bfs(work,src);
}

int UndirectedGraph::degree(int i)
{
     return adjacency->degree(i);
}
long long int UndirectedGraph::kruskal(MinPriorityQueue<tuple> q,int nodes)
{
    UFDS dsu(nodes);
    int x, y;
    long long cost, minimumCost = 0;
    while(!q.empty())
    {
        tuple temp=q.extract_min();
        x = temp.second;
        y = temp.third;
        cost=temp.first;
        if(!dsu.is_same_set(x,y))
        {
            src.push_back(x);
            dest.push_back(y);
            minimumCost += cost;
            dsu.union_set(x, y);
        }    
    }
    cout<<"\n";
    for(int i=0;i<src.size();i++)
    {
        cout<<src[i]<<"-->"<<dest[i]<<endl;
    }
    return minimumCost;
}

#endif /* ifndef UNDIRECTED_GRAPH */