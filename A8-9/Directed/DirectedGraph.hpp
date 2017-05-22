

/*

0 0 1 1 0
1 0 0 0 0
0 1 0 0 0
0 0 0 0 1
1 0 0 0 0

1 --- >   0 ----> 3 ---
^       /  ^          |
|      /   |          |
|     /    |          |
2 <--/     \ ---- 4 <--

1 0
0 2
2 1
1 0
0 3
4 0*/



#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "../stack.hpp"
#include "../queue.hpp"

#include "../AdjacencyMatrix.hpp"
#include "../AdjacencyList.hpp"

#include "../AbstractGraph.hpp"

#include <limits.h>

#include "../MinPriorityQueue.hpp"

#include "../UFDS.hpp"
/*
 * A class to represent a directed graph.
 */
class vertex{

  public:
    int v;
    int val;

  vertex()
  {

  }
  vertex (int v,int val)
  {
  	this->v=v;
  	this->val=val;
  }

  bool operator < (vertex rhs)
  {
    return this->val < rhs.val;
  }
  bool operator > (vertex rhs)
  {
    return this->val > rhs.val;
  }

  bool operator == (vertex rhs)
  {
    return (this->val == rhs.val) && (this->v == rhs.v);
  }   
  void operator = (vertex rhs)
  {
    
    this->v = rhs.v;
    this->val = rhs.val;
  }

  };


class edge{

  public:
    int src;
    int dest;
    int weight;

  edge()
  {

  }

  edge(int src,int dest,int weight)
  {
  	this->src = src;
    this->dest = dest;
    this->weight = weight;
  }

  bool operator < (edge rhs)
  {
    return this->weight < rhs.weight;
  }
  bool operator > (edge rhs)
  {
    return this->weight > rhs.weight;
  }

  bool operator == (edge rhs)
  {
    return (this->weight == rhs.weight) && (this->src == rhs.src) && (this->dest == rhs.dest);
  }   
  void operator = (edge rhs)
  {
    
    this->src = rhs.src;
    this->dest = rhs.dest;
    this->weight = rhs.weight;
  }

  };


class DirectedGraph : AbstractGraph {
  
private:AdjacencyMatrix graphm;
        AdjacencyList graphl;
        char repr;
        edge* mst;
        //int num_edges;

 public:

  DirectedGraph(int numVertices, char rep);

  int indegree(int i);

  int outdegree(int j);

  //int degree(int j){}


  bool edgeExists(int i, int j);
  
  int vertices();

  int edges();

  void add(int i, int j,int weight);

  void remove(int i, int j);

  void print();

  LinearList<DFSNode> dfs(void (*work)(int&),int src);

  LinearList<BFSNode> bfs(void (*work)(int&),int src);


  void printMST()
  {
  	cout<<"Source\t Destination\tWeight"<<endl;
  	for(int i=0;i<graphl.vertices()-1;i++)
                    {
                    cout<<"  "<<mst[i].src<<"\t\t"<<mst[i].dest<<"\t  "<<mst[i].weight<<endl;
                    }
  
                   
  }

  edge* kruskal()
  {
      MinPriorityQueue<edge> qedges;

      int n=graphl.vertices(),i;

      
      UFDS dset(n);

            for(int i=0;i<n;i++)
          {
              dset.make_set(i);
          }
			i=0;

      edge e;
      for(int i=0;i<n;i++)
          {
              listnode<pair<int,int> > *tmp=(graphl.AdjList())[i].init;
              while ( tmp!= NULL )        
              {   
                  e.src=i;
                  e.dest=(tmp->getdata()).first;
                  e.weight=(tmp->getdata()).second;
                  qedges.insert(e);
                  tmp = tmp->getlink();
              }

          }



    while(!qedges.empty())
    {
        e=qedges.extract_min();
        if(dset.find_set(e.src)!=dset.find_set(e.dest))
        {
            
            dset.union_set(e.src,e.dest);
            (this->mst)[i++]=e;
        }
  
    }
return mst;

  }

  edge* prim()
  {
	   int n=graphl.vertices();
	   
	   MinPriorityQueue<vertex> heap;
	   
	   int i,key[n],parent[n],weight[n];
	   
	   bool inMST[n];
	   
	   for(i=0;i<n;i++)
	   {
	   	inMST[i]=false;
	   	parent[i]=-1;
	   	weight[i]=INT_MAX;
	   	key[i]=INT_MAX;	   	
	   } 
	   vertex ver(0,0),u;
	   heap.insert(ver);
	   key[0]=0;
	   
	
	   while(!heap.empty())
	   {
	   	u=heap.extract_min();

	    inMST[u.v]=true;

		listnode<pair<int,int> >* tmp=(graphl.AdjList()[u.v].getfirst());
		while(tmp!=NULL)
			{
			int j=(tmp->getdata()).first;
			int wt=(tmp->getdata()).second;
			vertex ver(j,wt);

		    if( wt < key[j] &&!inMST[j]) 
		    {

		    	
		    	key[j]=wt;
		    	weight[j]=wt;
		    	parent[j]=u.v;
		    	vertex ver1(j,wt);
		    	heap.insert(ver1);

		    }

			tmp=tmp->getlink();
			}
			cout<<endl;
	   }

	   i=0;
	   for(i=1;i<n;i++)
	   {
	   	edge e(parent[i],i,weight[i]);
	   	this->mst[i-1]=e;
	   }

  return mst;

  }

};

 DirectedGraph::DirectedGraph(int numVertices, char rep)
 {
    if(rep=='m') graphm.resAdjacencyMatrix(numVertices);

    else if(rep=='l') graphl.resAdjacencyList(numVertices);

    repr=rep;

    //num_edges=0;
 }


 LinearList<DFSNode> DirectedGraph::dfs(void (*work)(int&),int src)
  {
        int n=this->vertices(),time=0;
        LinearList<DFSNode> tree(n);

        for(int i=0;i<n;i++)
        {
          tree[i].col=WHITE;
          tree[i].pred=make_pair(-1,0);
        }
        
        stack<int> s;
        s.push(src);
        
          while(!s.empty())
          {
             int i=s.top();
             if(tree[i].col==BLACK)
             {
              s.pop();
             }
             else if(tree[i].col==GRAY)
             {
              s.pop();
              tree[i].col=BLACK;
              time++;
              tree[i].ft=time;
             }
             else if(tree[i].col==WHITE)
             {
                 tree[i].col=GRAY;
                 work(i);
                 time++;
                 tree[i].dt=time;
               
                  if(repr=='m')
                  {
                       for(int j=0;j<n;j++)
                       {
                        if(this->edgeExists(i,j) && tree[j].col==WHITE ) 
                        {
                          s.push(j);
                          tree[j].pred=make_pair(i,graphm.weight_of(i,j));;
                        }
                       }
                  }
                  else
                    {
                      listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
                      while(tmp!=NULL)
                      {
                        int j=(tmp->getdata()).first;
                        if(tree[j].col==WHITE)
                        {
                          s.push(j);
                          tree[j].pred=make_pair(i,(tmp->getdata()).second);
                        }
                        tmp=tmp->getlink();
                      }
                      
                    }
              }
            }

              for(int k=0;k<n;k++)
              {

              if(tree[k].col==WHITE)
              {
                s.push(k);
              }

             while(!s.empty())
             {
             int i=s.top();
            
                if(tree[i].col==BLACK) s.pop();
                
                else if(tree[i].col==GRAY)
                {
                s.pop();
                tree[i].col=BLACK;
                time++;
                tree[i].ft=time;
                  }
                
                else if(tree[i].col==WHITE)
                {
                    work(i);
                    tree[i].col=GRAY;
                    time++;
                    tree[i].dt=time;
       
       
                  if(repr=='m')
                  {
                       for(int j=0;j<n;j++)
                       {
                        if(this->edgeExists(i,j) && tree[j].col==WHITE ) 
                        {
                          s.push(j);
                          tree[j].pred=make_pair(i,graphm.weight_of(i,j));
                        }
                       }
                    }
                    else
                    {
                      listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
                      while(tmp!=NULL)
                      {
                        int j=(tmp->getdata()).first;
                        if(tree[j].col==WHITE)
                        {
                          s.push(j);
                          tree[j].pred=make_pair(i,(tmp->getdata()).second);
                      }
                        tmp=tmp->getlink();
                      }
                      
                    }


               }
            }

          }
              
  return tree;

  }

 LinearList<BFSNode> DirectedGraph::bfs(void (*work)(int&),int src)
 {
              int n=this->vertices();

        LinearList<BFSNode> tree(n);
        for(int i=0;i<n;i++)
        {
          tree[i].col=WHITE;
          tree[i].pred=make_pair(-1,0);
          tree[i].d=0;

        }
        
        queue<int> q;
        q.push(src);
        tree[src].col=GRAY;
        work(src);
        while(!q.empty())
        {
         int i=q.pop();
         tree[i].col=BLACK; 
    if(repr=='m')
      {
          for(int j=0;j<n;j++)
          {
            if(this->edgeExists(i,j) && tree[j].col==WHITE) 
            {
              q.push(j);
              tree[j].col=GRAY;
              
              tree[j].d=tree[i].d+1;
              tree[j].pred=make_pair(i,graphm.weight_of(i,j));
            work(j);
            }
          }
        }
        else
        {
          listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
              while(tmp!=NULL)
              {
                int j=(tmp->getdata()).first;
                if(tree[j].col==WHITE)
                {
                  q.push(j);
                  tree[j].col=GRAY;
                  tree[j].d=tree[i].d+1;
                  tree[j].pred=make_pair(i,(tmp->getdata()).second);
                  work(j);
                }
                tmp=tmp->getlink();
              }
        }
         
        
        } 
        return tree;
 }


  int DirectedGraph::indegree(int i)
  {
    if(repr=='m') return graphm.indegree(i);
    else return graphl.indegree(i);
  }

  int DirectedGraph::outdegree(int j)
  {
    if(repr=='m') return graphm.outdegree(j);
    else return graphl.outdegree(j);
  }
 
 bool DirectedGraph::edgeExists(int i, int j)
  {
    if(repr=='m') return graphm.edgeExists(i,j);
    else return graphl.edgeExists(i,j);
  }
  
  int DirectedGraph::vertices()
  {
    if(repr=='m') return graphm.vertices();
    else return graphl.vertices();
  } 

  int DirectedGraph::edges()
  {
    if(repr=='m') return graphm.edges();
    else return graphl.edges();
  }

  void DirectedGraph::add(int i, int j,int weight)
  {
    if(repr=='m') graphm.add(i,j,weight);
    else graphl.add(i,j,weight);

    

  }

  void DirectedGraph::remove(int i, int j)
  {
    if(repr=='m') graphm.remove(i,j);
    else graphl.remove(i,j);
  }

    void DirectedGraph::print()
  {
    if(repr=='m') graphm.print();
    else graphl.print();
  }


#endif /* ifndef DIRECTED_GRAPH */