#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "../stack.hpp"
#include "../queue.hpp"

#include "../AdjacencyMatrix.hpp"
#include "../AdjacencyList.hpp"

#include "../AbstractGraph.hpp"


class UndirectedGraph : AbstractGraph {

  private:AdjacencyMatrix graphm;
        AdjacencyList graphl;
        char repr;

 public:
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UndirectedGraph(int vertices, char mode);

  bool edgeExists(int i, int j);

  void print();

  int edges();

  int vertices();

  void add(int i, int j);

  void remove(int i, int j);

  void dfs(void (*work)(int&),int src);

  void bfs(void (*work)(int&),int src);

  int degree(int i);

  //int indegree(int i){}

  //int outdegree(int i){}

};

UndirectedGraph::UndirectedGraph(int vertices, char mode)
{

    if(mode=='m') graphm.resAdjacencyMatrix(vertices);

    else if(mode=='l') graphl.resAdjacencyList(vertices);

    repr=mode;

}

  bool UndirectedGraph::edgeExists(int i, int j)
  {
    if(repr=='m') return graphm.edgeExists(i,j);
    else return graphl.edgeExists(i,j);
  }

  int UndirectedGraph::edges()
  {
    if(repr=='m') return graphm.edges()/2;
    else return graphl.edges()/2;
  } 

  int UndirectedGraph::vertices()
  {
    if(repr=='m') return graphm.vertices();
    else return graphl.vertices();
  }

  void UndirectedGraph::add(int i, int j)
  {
    if(repr=='m') 
    {
      graphm.add(i,j);
      graphm.add(j,i);
    }
    else 
      {
        graphl.add(i,j);
        graphl.add(j,i);
      }
  }

  void UndirectedGraph::remove(int i, int j)
  {
    if(repr=='m') 
      {
        graphm.remove(i,j);
        graphm.remove(j,i);
      }
    else 
    {
      graphl.remove(i,j);
      graphl.remove(i,j);
    }
  }


  void work(int& v)
  {
  	cout<<" "<<v<<" ";
  }

  void UndirectedGraph::dfs(void (*work)(int&),int src)
  {

    		int n=this->vertices();
  			Color col[n];
  			bool is_in_queue[n];
  			for(int i=0;i<n;i++)
  			{
  				col[i]=WHITE;
  				is_in_queue[i]=false;
  			}
  			
  			stack<int> s;
  			s.push(src);


  			while(!s.empty())
  			{
 			 int i=s.pop();
  			 if(col[i]==WHITE) 
  			 	{
		  			 work(i);
		  			 col[i]=GRAY;
		 	 		if(repr=='m')
		 	 		{
			  			 for(int j=n-1;j>=0;j--)
			  			 {
			  			 	if(this->edgeExists(i,j) && col[j]==WHITE ) 
			  			 	{
			  			 		s.push(j);
			  			 		//is_in_queue[i]=true;
			  			 	}
			  			 }
		  			}
		  			else
		  			{
		  				//cout<<(graphl.AdjList()[i].getfirst())->getdata()<<endl;

			  			listnode<int>* tmp=(graphl.AdjList()[i].getfirst());
			  			while(tmp!=NULL)
			  			{
			  				int j=tmp->getdata();
			  				if(col[j]==WHITE&&!is_in_queue[i])
			  				{
			  					s.push(j);
			  					is_in_queue[i]=true;

			  				}
			  				tmp=tmp->getlink();
			  			}
		  				
		  			}

		  			 col[i]=BLACK;
		  		

  				}	
  		  	
  		  	}
  		  	cout<<endl;
  }

  void UndirectedGraph::bfs(void (*work)(int&),int src)
  {

  			int n=this->vertices();
  			Color col[n];
  			for(int i=0;i<n;i++)
  			{
  				col[i]=WHITE;
  			}
  			
  			queue<int> q;
  			q.push(src);
  			col[src]=GRAY;
  			work(src);

  			while(!q.empty())
  			{
  			 int i=q.pop();
  			 
		if(repr=='m')
			{
	  			for(int j=0;j<n;j++)
	  			{
	  			 	if(this->edgeExists(i,j) && col[j]==WHITE) 
	  			 	{
	  			 		q.push(j);
	  			 		col[j]=GRAY;
	  			 		work(j);
	  			 	}
	  			}
  			}
  			else
  			{
  				listnode<int>* tmp=(graphl.AdjList()[i].getfirst());
			  			while(tmp!=NULL)
			  			{
			  				int j=tmp->getdata();
			  				if(col[j]==WHITE)
			  				{
			  					q.push(j);
			  					col[j]=GRAY;
	  			 				work(j);
			  					//is_in_queue[i]=true;

			  				}
			  				tmp=tmp->getlink();
			  			}
  			}
  			 col[i]=BLACK;
  			
  			}	
  	cout<<endl;		
  }

  int UndirectedGraph::degree(int i)
  {
    if(repr=='m') return graphm.outdegree(i);
    else return graphl.outdegree(i);
  }

  void UndirectedGraph::print()
  {
    if(repr=='m') graphm.print();
    else graphl.print();
  }


#endif /* ifndef UNDIRECTED_GRAPH */