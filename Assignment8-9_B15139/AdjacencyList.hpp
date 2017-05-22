#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"
#include <cstring>
#include <cstdlib>
#include "list.hpp"
#include "stack.hpp"
#include "dsu.hpp"
#include "MinPriorityQueue.hpp"
using namespace std;
using namespace cs202;
class AdjacencyList : public GraphAdjacencyBase {
private:
	int vertex;
	LinearList<LinearList<int> > adj_list;
	LinearList<LinearList<twin> > twin_list;
	LinearList<bool> marked;
	UFDS *ds;
public:
	AdjacencyList(int vertices);
 // ~AdjacencyList();
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
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
   void add(int i, int j,int weight);
   void addtwin(int i,twin p)
   {
   	twin_list[i].push_back(p);
   }
   long long prim(int x)
  {
    	MinPriorityQueue<twin> q;
    int y;
    long long minimumCost = 0;
    twin p,temp;
    temp.set_parameters(0,x);
    q.insert(temp);
    while(!q.empty())
    {
        // Select the edge with minimum weight
        p =q.extract_min();
        x = p.second;
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i <twin_list[x].size();++i)
        {
            y = twin_list[x][i].second;
            if(marked[y] == false)
            {
            	temp.set_parameters(twin_list[x][i].first,twin_list[x][i].second);
                q.insert(temp);
           }
        }
    }
    return minimumCost;
  }
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
   			cout<<i<<" --> ";
   			for(int j=0;j<twin_list[i].size();j++)
   				cout<<"first "<<twin_list[i][j].first<<" "<<"second "<<twin_list[i][j].second<<endl;
   			cout<<"\n";
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
AdjacencyList::AdjacencyList(int vertices)
{
	this->vertex=vertices;
	adj_list.resize(vertex);
	ds=new UFDS(vertices);
	
}
bool AdjacencyList::edgeExits(int i, int j)
{
	int flag=false;
	for(int k=0;k<twin_list[i].size();k++)
	{
		if(twin_list[k][i].second==j)
		{
			flag=true;
			break;
		}
	}
	if(flag)
		return true;
	 return false;
}

int AdjacencyList::edges()
{
	int edge_size=0;
	for(int i=0;i<vertex;i++)
	{
		edge_size+=twin_list[i].size();
	}
	return edge_size;
}

int AdjacencyList::vertices()
{
	return vertex;
}

void AdjacencyList::add(int i, int j,int weight)
{
	
	adj_list[i].push_back(j);

}

void AdjacencyList::remove(int i, int j)
{
	int ind;
	for(int k=0;k<twin_list[i].size();k++)
		if(twin_list[i][k].second==j)
		{
			ind=k;
			cout<<"k found "<<k<<endl;
			break;
		}
	// for(int k=ind;k<twin_list[i].size()-1;k++)
	// {
	// 	twin_list[i][k].first=twin_list[i][k+1].first;
	// 	twin_list[i][k].second=twin_list[i][k+1].second;
	// }

	
}



int AdjacencyList::degree(int i)
{
	
	return twin_list[i].size();
}

int AdjacencyList::indegree(int i)
{
	int ct=0;
	for(int k=0;k<vertex;k++)
	{
		for(int l=0;l<twin_list[k].size();l++)
		{
			if(twin_list[k][l].second==i)
				ct++;
		}
	}
	return ct;
}

int AdjacencyList::outdegree(int i)
{
	return twin_list[i].size();
}

void AdjacencyList::dfs(void (*work)(int&),int src)
{
    LinearList<bool> visited(vertex,false);
    stack<int> s;
    s.push(src);
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(!visited[top])
        {
            visited[top]=true;
            work(top);
        }
        for(int i=0;i<twin_list[top].size();i++)
        {
            if(!visited[twin_list[top][i].second])
                s.push(twin_list[top][i].second);
        }
    }
    
}

void AdjacencyList::bfs(void (*work)(int&),int src)
{
    LinearList<bool> visited(vertex,false);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
    	
        int top=q.front();
       
        work(top);
        q.pop();
       

        for(int i=0;i<twin_list[top].size();i++)
        {
        	
             if(visited[twin_list[top][i].second]==false)
             {
            	
                q.push(twin_list[top][i].second);
            
               visited[twin_list[top][i].second]=true;
             }
         
        }
      
    } 
 
}

#endif /* ifndef ADJACENCY_LIST */
