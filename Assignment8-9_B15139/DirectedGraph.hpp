#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"

using namespace std;
//using namespace cs202;
 #include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {
private:
 public:
  twin p;
      int vertice;
     GraphAdjacencyBase *adjacency;
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int vertices, char mode);
   int degree(int i);
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int indegree(int i);
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int outdegree(int j);

   /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool edgeExits(int i, int j);

  long long prim(int x)
  {
    
  }
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
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  void remove(int i, int j);
  // void addtwin(int i,twin p)
  // {
  //   adjacency->addtwin(i,p);
  // }
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
};
DirectedGraph::DirectedGraph(int vertices, char mode)
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

bool DirectedGraph::edgeExits(int i, int j)
{
    return adjacency->edgeExits(i,j);
}

int DirectedGraph::edges()
{
     return (adjacency->edges());
}

int DirectedGraph::vertices()
{
     return adjacency->vertices();
}

void DirectedGraph::add(int i, int j,int weight)
{
       p.set_parameters(weight,j);
        adjacency->addtwin(i,p);
}

void DirectedGraph::remove(int i, int j)
{
     adjacency->remove(i,j);
}

void DirectedGraph::dfs(void (*work)(int&),int src)
{
    adjacency->dfs(work,src);
}

void DirectedGraph::bfs(void (*work)(int&),int src)
{
     adjacency->bfs(work,src);
}

int DirectedGraph::indegree(int i)
{
     adjacency->indegree(i);
}

int DirectedGraph::outdegree(int i)
{
     adjacency->outdegree(i);
}
int DirectedGraph::degree(int i)
{
     
}
#endif /* ifndef DIRECTED_GRAPH */
