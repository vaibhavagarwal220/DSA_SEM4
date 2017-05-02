

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
#include "../AbstractGraph.hpp"
#include "../AdjacencyMatrix.hpp"
#include "../AdjacencyList.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {
  
private:AdjacencyMatrix graphm;
        AdjacencyList graphl;
        char repr;
 public:

  DirectedGraph(int numVertices, char rep);

  int indegree(int i);

  int outdegree(int j);

  //int degree(int j){}


  bool edgeExists(int i, int j);
  
  int vertices();

  int edges();

  void add(int i, int j);

  void remove(int i, int j);

  void print();

  void dfs(void (*work)(int&));

  void bfs(void (*work)(int&),int src);
};

 DirectedGraph::DirectedGraph(int numVertices, char rep)
 {
    if(rep=='m') graphm.resAdjacencyMatrix(numVertices);

    else if(rep=='l') graphl.resAdjacencyList(numVertices);

    repr=rep;
 }


 void DirectedGraph::dfs(void (*work)(int&))
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

 void DirectedGraph::bfs(void (*work)(int&),int src)
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

  void DirectedGraph::add(int i, int j)
  {
    if(repr=='m') graphm.add(i,j);
    else graphl.add(i,j);

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