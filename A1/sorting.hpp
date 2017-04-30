#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"
#include <time.h>


template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high)
		{	

			  int c,d,t;
			  for (c = low ; c < high ; c++) 
			  {
			    d = c;
			 
			    while ( d > 0 && A[d] < A[d-1]) 
			    {
			      t  = A[d];
			      A[d]   = A[d-1];
			      A[d-1] = t;
			 
			      d--;
			    }
			  }

		}
		void bubbleSort(LinearList<Item>& A, int low, int high)
		{
			for (int c = low-1 ; c < ( high - 1 ); c++)
			  {
			    for (int d = low-1 ; d < high - c - 1; d++)
			    {
			      if (A[d] > A[d+1]) /* For decreasing order use < */
			      {
			        int swap       = A[d];
			        A[d]   = A[d+1];
			        A[d+1] = swap;
			      }
			    }
			  }
		}
	 	void rankSort(LinearList<Item>& A, int low, int high)
	 	{
	 		    
	 		    LinearList<Item> rank(high-low+1),b(high-low+1);
	 		    for(int i=low-1;i<high;i++)
                rank[i]=0;
        		for(int i=low-1;i<high;i++)
                	for(int j=low-1;j<i;j++)
                        if(A[j]>A[i])rank[j]++;
                        else rank[i]++;
		        for(int i=low-1;i<high;i++)
		                b[rank[i]]=A[i];
		        for(int i=low-1;i<high;i++)
		                A[i]=b[i];
	 	}
        
        void selectionSort(LinearList<Item>& A, int low, int high)
        {
        	int position;
        	for (int c = low-1 ; c < ( high - 1 ) ; c++ )
			   {
			      position = c;
			 
			      for (int d = c + 1 ; d < high ; d++ )
			      {
			         if ( A[position] > A[d] )
			            position = d;
			      }
			      if ( position != c )
			      {
			         int swap = A[c];
			         A[c] = A[position];
			         A[position] = swap;
			      }
			   }	
        }

//		void mergeSort(LinearList<Item>& A, int low, int high);
//            	void quickSort(LinearList<Item>& A, int low, int high);
};

#endif
