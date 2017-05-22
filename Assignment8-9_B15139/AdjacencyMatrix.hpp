#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"
#include <cstring>
#include <cstdlib>
#include "pair.hpp"
using namespace std;
using namespace cs202;
class AdjacencyMatrix : public GraphAdjacencyBase {
private:
	int edge_count,vertex;
	LinearList<LinearList<int> > adj_matrix;
public:
	AdjacencyMatrix(int vertices);
 // ~AdjacencyMatrix();
  /*VIRTUAL*/
  /*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
   bool edgeExits(int i, int j);
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
   int vertices();
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
   int edges();
   void addtwin(int i,twin p)
   {

   }
   long long prim(int x)
	  {
	    
	  }
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
   void add(int i, int j,int weight);
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
   int indegree(int i);
   int outdegree(int i);
   void remove(int i, int j);
   void print()
   {
   		for(int i=0;i<vertex;i++)
   		{
   			for(int j=0;j<vertex;j++)
   			{
   				cout<<adj_matrix[i][j]<<" ";
   			}
   			cout<<endl;
   		}
   }
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
   int degree(int i);
   void dfs(void (*work)(int&),int src);
   void bfs(void (*work)(int&),int src);
   
};
AdjacencyMatrix::AdjacencyMatrix(int vertices)
{
	//adj_matrix=(int*)malloc
	this->vertex=vertices;
	adj_matrix.resize(vertex);
	for(int i=0;i<vertex;i++)
	{
		adj_matrix[i].resize(vertex);
		adj_matrix[i].fill(0);
	}
}
bool AdjacencyMatrix::edgeExits(int i, int j)
{
	if(adj_matrix[i][j]==1)
		return true;
	return false;
}

int AdjacencyMatrix::edges()
{
return (this->edge_count);
}

int AdjacencyMatrix::vertices()
{
	return vertex;
}

void AdjacencyMatrix::add(int i, int j,int weight)
{
	// cout<<"here i am\n";
	// if(i>max_row)
	// 	max_row=i;
	// if(j>max_col)
	// 	max_col=j;
	adj_matrix[i][j]=1;
	this->edge_count++;
	// cout<<adj_matrix[i][j];
	// cout<<"here i end\n";

}

void AdjacencyMatrix::remove(int i, int j)
{
	adj_matrix[i][j]=0;
	this->edge_count--;
}

// void AdjacencyMatrix::dfs(void (*work)(int&))
// {

// }

// void AdjacencyMatrix::bfs(void (*work)(int&))
// {

// }

int AdjacencyMatrix::degree(int i)
{
	cout<<"degree\n";
	int count=0;
	cout<<"ver "<<this->vertex<<endl;
	for(int k=0;k<(this->vertex);k++)
	{
		if(adj_matrix[i][k]==1)
		{
			cout<<"ct\n";
			count++;
		}
	}
	return count;
}

int AdjacencyMatrix::indegree(int i)
{
	int in_count=0;
	for(int k=0;k<vertex;k++)
	{
		if(adj_matrix[k][i]==1)
			in_count++;
	}
	return in_count;
}

int AdjacencyMatrix::outdegree(int i)
{
	int out_count=0;
	for(int k=0;k<vertex;k++)
	{
		if(adj_matrix[i][k]==1)
			out_count++;
	}
	return out_count;
}
void AdjacencyMatrix::dfs(void (*work)(int&),int src)
{

}
void AdjacencyMatrix::bfs(void (*work)(int&),int src)
{
	
}
#endif /* ifndef ADJACENCY_MATRIX */
