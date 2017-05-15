

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
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {
  
private:AdjacencyMatrix graphm;
        AdjacencyList graphl;
        char repr;
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