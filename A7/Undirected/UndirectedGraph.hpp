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

  void dfs(void (*work)(int&));

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


  void UndirectedGraph::dfs(void (*work)(int&))
  {

    		int n=this->vertices();
  			Color col[n];
  			int pred[n],time=0,dt[n],ft[n];

  			for(int i=0;i<n;i++)
  			{
  				col[i]=WHITE;
  				pred[i]=-1;
  			}
  			
  			stack<int> s;
  			//s.push(src);

  			for(int k=0;k<n;k++)
  			{

  			if(col[k]==WHITE)
  			{
  				col[k]=GRAY;
  				time++;
  				dt[k]=time;
  				s.push(k);
  			}

  			while(!s.empty())
  			{
 			 int i=s.pop();
 			 work(i);
		  	 if(pred[i]!=-1) cout<<"Discovery Time = "<<dt[i]<<" Predecessor "<<pred[i]<<" ";
  			 else cout<<"Discovery Time = "<<dt[i]<<" Predecessor NIL "; 
 	 		if(repr=='m')
 	 		{
	  			 for(int j=0;j<n;j++)
	  			 {
	  			 	if(this->edgeExists(i,j) && col[j]==WHITE ) 
	  			 	{
	  			 		s.push(j);
	  			 		col[j]=GRAY;
	  			 		time++;
	  			 		dt[j]=time;
	  			 		pred[j]=i;
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
	  				if(col[j]==WHITE)
	  				{
	  					s.push(j);
	  					col[j]=GRAY;
	  			 		time++;
	  			 		dt[j]=time;
	  			 		pred[j]=i;


	  				}
	  				tmp=tmp->getlink();
	  			}
  				
  			}

  			 col[i]=BLACK;
  			 time++;
  			 ft[i]=time;
  			 cout<<"Finishing Time = "<<ft[i]<<endl;
  		  	}

  			}
  			
  }

  void UndirectedGraph::bfs(void (*work)(int&),int src)
  {

  			int n=this->vertices();
  			Color col[n];
  			int pred[n];
  			int d[n];
  			for(int i=0;i<n;i++)
  			{
  				col[i]=WHITE;
  				pred[i]=-1;
  				d[i]=0;

  			}
  			
  			queue<int> q;
  			q.push(src);
  			col[src]=GRAY;
  			work(src);
  			cout<<"Distance from Source = "<<d[0]<<" Predecessor NIL";
  			cout<<endl;

  			while(!q.empty())
  			{
  			 int i=q.pop();
  			 col[i]=BLACK; 
		if(repr=='m')
			{
	  			for(int j=0;j<n;j++)
	  			{
	  			 	if(this->edgeExists(i,j) && col[j]==WHITE) 
	  			 	{
	  			 		q.push(j);
	  			 		col[j]=GRAY;
	  			 		
	  			 		d[j]=d[i]+1;
	  					pred[j]=i;
		 				work(j);
		 				cout<<"Distance from Source = "<<d[j]<<" Predecessor "<<pred[j];
		 				cout<<endl;
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
			  					d[j]=d[i]+1;
			  					pred[j]=i;
	  			 				work(j);
	  			 				cout<<"Distance from Source = "<<d[j]<<" Predecessor "<<pred[j];
	  			 				cout<<endl;
			  				}
			  				tmp=tmp->getlink();
			  			}
  			}
  			 
  			
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