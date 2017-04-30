#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"
#include <time.h>
#include <limits.h>
namespace cs202{
template<class T>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<T>& A, int low, int high)
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
		void bubbleSort(LinearList<T>& A, int low, int high)
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
	 	void rankSort(LinearList<T>& A, int low, int high)
	 	{
	 		    
	 		    LinearList<T> rank(high-low+1),b(high-low+1);
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
        
        void selectionSort(LinearList<T>& A, int low, int high)
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




				void merge(LinearList<T>& A, int p, int q,int r)
				{
					int n1=q-p+1;
					int n2=r-q;
					LinearList<T> A1(n1+1),A2(n2+1);
					A1[n1]=INT_MAX,A2[n2]=INT_MAX;
					//cout<<"A1"<<endl;
					for(int i=0;i<n1;i++)
						{A1[i]=A[p+i];// cout<<A1[i]<<" ";
				}
					

			//cout<<"A2"<<endl;
					for(int i=0;i<n2;i++)
						{A2[i]=A[q+1+i];//cout<<A2[i]<<" ";
				}
					
					int i=0,j=0;

					for(int k=p;k<=r;k++)
					{
						if(A1[i]<=A2[j])
						{
							A[k]=A1[i];
							i++;
						}
						else
						{
							A[k]=A2[j];
							j++;
						}
					}

				}






				void mergeSort(LinearList<T>& A, int p, int r)
				{	int q;
					if(p<r)
						{

							q=(p+r)/2;
							//cout<<p<<" "<<q<<" "<<r<<endl;
							mergeSort(A,p,q);					
							mergeSort(A,q+1,r);
							merge(A,p,q,r);
						}
					

				}


            	void quickSort(LinearList<T>& A, int p, int r)
            	{
            		if(p<r)
            		{
            			int q=partition(A,p,r);
            			quickSort(A,p,q);
            			quickSort(A,q+1,r);
            		}
            	}
            	int partition(LinearList<T>& A,int p,int r)
            	{
            		int pivot=A[r];
            		int i=p-1;
            		int j=r+1;
            		while(1)
            		{
            			do
            			{j--;}
            			while(A[j]>pivot);

            			do
            			{i++;}
            			while(A[i]<pivot);

            			if(j>i)
            			{
            				int tmp=A[i];
            				A[i]=A[j];
            				A[j]=tmp;

            			}
            			else if(j=i)
            				return j-1;
            			else 
            				return j;
            		}
            	}
};
}
#endif
