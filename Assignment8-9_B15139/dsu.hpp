// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef UFDS_
#define UFDS_ 1

#include "seqLinearList.hpp"

namespace cs202 {

class UFDS {
  // Private attributes and functions for class
  // If you want to add any more variables, please add them
  // and give a valid reason for their use.
  // DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
  // YOU NEED TO USE THEM ALL.

  // node in consideration for union find data structure
  // stores parent and rank for each vertex
  // You may add new members to the node, with explanation as to
  // why the members were necessary.
  class node {
    public:
      int parent;
      int rank;
  };

  LinearList<node> vertex;
  LinearList<int> size;

  public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(const unsigned int& N);

    // Default constructor
//    ~UFDS();

    // Make a new set with N vertices with all sets being disjoint
    void make_set (const unsigned int& N);

    // Return the representative / parent of set consisting of object x.
    int find_set (const unsigned int& x);
    
    // Unite sets containing objects x and y.
    void union_set (const unsigned int& x, const unsigned int& y);
    
    // Are objects x and y in the same set?
    bool is_same_set (const unsigned int& x, const unsigned int& y);

    // Return the number of disjoint sets.
    int num_disjoint_sets();
    
    // Return the size of the set containing object x.
    int size_set (const unsigned int& x); 
  }; 

  UFDS::UFDS(const unsigned int& N)
  {
     vertex.resize(N);
     size.resize(N);
     for(int i=0;i<N;i++)
     {
          vertex[i].rank=0;
          vertex[i].parent=i;
          size[i]=1;
     }
  }

  void UFDS::make_set (const unsigned int& N)
  {

  }

  int UFDS::find_set (const unsigned int& x)
  {
     int temp=x;
     while(vertex[temp].parent!=temp)
     {
          temp=vertex[vertex[temp].parent].parent;
     }
     vertex[x].parent=temp;
     return temp;
  }

  void UFDS::union_set (const unsigned int& x, const unsigned int& y)
  {
     int root_x=find_set(x);
     int root_y=find_set(y);
     if(vertex[root_x].rank<vertex[root_y].rank)
     {
          vertex[root_x].parent=vertex[root_y].parent;
          size[root_y]+=size[root_x];
     }
     else if(vertex[root_x].rank>vertex[root_y].rank)
     {
          vertex[root_y].parent=vertex[root_x].parent;
          size[root_x]+=size[root_y];
     }
     else
     {
          vertex[root_x].parent=vertex[root_y].parent;
          size[root_y]+=size[root_x];
          vertex[root_y].rank++;
     }
  }

  bool UFDS::is_same_set (const unsigned int& x, const unsigned int& y)
  {
     if(find_set(x)==find_set(y))
          return true;
     return false;
  }

  int UFDS::num_disjoint_sets()
  {
     int count=0;
     for(int i=0;i<vertex.size();i++)
          if(vertex[i].parent==i)
               count++;
     return count;
  }

  int  UFDS::size_set (const unsigned int& x)
  {
     int index=find_set(x);
     return size[index];
  }

}

#endif  /* UFDS_ */
