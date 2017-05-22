#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG 1
#include "pair.hpp"
/*
 * A base class which can denote any Graph Adjacency representation.
 * Subclasse by AdjacencyMatrix and AdjacencyList
 * Use this class in your graphs to be able to select any representation as desired by the user.
 */
class GraphAdjacencyBase {
	/* Destructor:
	 * releases all resources acquired by the class
	 */
  // virtual ~GraphAdjacencyBase();
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
public:
  virtual bool edgeExits(int i, int j) = 0;
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  virtual int vertices() = 0;
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  virtual int edges() = 0;
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  virtual void add(int i, int j,int weight) = 0;
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  virtual void remove(int i, int j) = 0;
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  virtual int degree(int i) = 0;
  virtual void print()=0;
  virtual int indegree(int i) = 0;
  virtual int outdegree(int i) = 0;
  virtual void dfs(void (*work)(int&),int src) = 0;
  virtual void addtwin(int i,twin p)=0;
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  virtual void bfs(void (*work)(int&),int src) = 0;
  virtual long long prim(int x)=0;
};
#endif /* ifndef GRAPH_ADJACENCY_BAG */
