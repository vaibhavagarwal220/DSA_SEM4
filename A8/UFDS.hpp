// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef UFDS_
#define UFDS_ 1
#include <iostream>
using namespace std;
#include "seqLinearList.hpp"

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
      int size;
  };

  LinearList<node> vertex;
  int num_dis_sets;

  public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(const unsigned int& N);

    // Default constructor
    ~UFDS();

    // Make a new set with N vertices with all sets being disjoint
    void make_set (const unsigned int& N);

    // Return the representative / parent of set consisting of object x.
    int find_set (const unsigned int& x);
    
    // Unite sets containing objects x and y.
    void union_set (const unsigned int& x, const unsigned int& y);

    void link (const unsigned int& x, const unsigned int& y);
    
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
    	num_dis_sets=N;

    }

    // Default constructor
    UFDS::~UFDS()
    {

    }

    // Make a new set with N vertices with all sets being disjoint
    void UFDS::make_set (const unsigned int& N)
    {
    	vertex[N].parent=N;
    	vertex[N].rank=0;
    	vertex[N].size=1;


    }

    // Return the representative / parent of set consisting of object x.
    int UFDS::find_set (const unsigned int& x)
    {
    if (x != vertex[x].parent) 	
    {
		    vertex[x].parent = find_set(vertex[x].parent);
	}
 	return (vertex[x].parent);

    }
    
    // Unite sets containing objects x and y.
    void UFDS::union_set (const unsigned int& x, const unsigned int& y)
    {
    	
    	link(find_set(x), find_set(y));
    	num_dis_sets--;
    }
    
    void UFDS::link (const unsigned int& x, const unsigned int& y){
    	if (vertex[x].rank > vertex[y].rank)
			{
				vertex[y].parent = x;
			(vertex[x].size)++;	
			}
		else 
		{
			vertex[x].parent = y;
			if (vertex[x].rank == vertex[y].rank)
				vertex[y].rank = vertex[y].rank+1;

			(vertex[y].size)++;
		}


    }
    // Are objects x and y in the same set?
    bool UFDS::is_same_set (const unsigned int& x, const unsigned int& y)
    {
	    return (find_set(x)==find_set(y));	
    }

    // Return the number of disjoint sets.
    int UFDS::num_disjoint_sets()
    {
    	return num_dis_sets;
    }

    // Return the size of the set containing object x.
    int UFDS::size_set (const unsigned int& x) 
    {
    	return vertex[(find_set(x))].size;
    }

#endif  /* UFDS_ */
