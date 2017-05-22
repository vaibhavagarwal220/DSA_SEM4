// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqLinearList.hpp"

using namespace std;
using namespace cs202;

 namespace cs202{
 	
 	template<class T>
 	class MinPriorityQueue{
 		// Primary container used in MinPriorityQueue
 		LinearList<T> heap;
 		int heap_size;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos);

 		// return the parent of an element
 		inline int parent(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);

 	public:
 		// default constructor
 		MinPriorityQueue();

 		// construct a heap from the elements of a seqLinearList
 		MinPriorityQueue(LinearList<T>& v);

 		// insert a value to the heap
 		void insert(const T& a);

 		// get the minimum element from the heap
 		inline T minimum();

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int size();

 		// build a heap from elements of a seqLinearList container 
 		void build_heap(LinearList<T> v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);

 		void print();
 	};



 		 		template<class T>
 	 	void MinPriorityQueue<T>::heapify(const size_t& pos)
 	 	{
 	 		int l=this->left_child(pos);
 	 		int r=this->right_child(pos);
 	 		//cout<<heap[l]<<endl;
 	 		//cout<<heap[r]<<endl;
 	 		T tmp;
 	 		int smallest;
// 	 		cout<<heap.size()<<endl;
 	 		if(l<heap_size &&heap[l]<heap[pos])
 	 			smallest=l;
 	 		else smallest=pos;
 	 		if(r<heap_size &&heap[r]<heap[smallest])
 	 			smallest=r;
 	 		if(smallest!=pos)
 	 		{
 	 			//cout<<smallest<<endl;
 	 			tmp=heap[pos];
 	 			heap[pos]=heap[smallest];
 	 			//cout<<tmp;
 	 			heap[smallest]=tmp;
 	 			heapify(smallest);
 	 		}
 	 		//cout<<pos<<endl;
 	 		return;

 	 	}

 		// return the parent of an element
 		 		template<class T>
 	 	inline int MinPriorityQueue<T>::parent(const size_t& pos)
 	 	{
 	 		return (pos-1)/2;
 	 	}
 	 	
 		// return the left child of an element
 		 		template<class T>
 	 	inline int MinPriorityQueue<T>::left_child(const size_t& pos)
 	 	{
 	 		return 2*pos + 1;
 	 	}
 	 	
 		// return the right child of an element
 		 		template<class T>
 	 	inline int MinPriorityQueue<T>::right_child(const size_t& pos)
 	 	{
 	 		return 2*pos + 2;
 	 	}
 	 	


 		template<class T>
 	 	MinPriorityQueue<T>::MinPriorityQueue()
 	 	{
 	 		heap_size=0;
 	 	}

 		// construct a heap from the elements of a seqLinearList
 		template<class T>
 		MinPriorityQueue<T>::MinPriorityQueue(LinearList<T>& v)
 	 	{
 	 		int n=v.size();

 	 		//if(n>heap.size()) heap.resize(n);
 	 		heap_size=0;
 	 		for(int i=0;i<n;i++)
 	 		{
 	 			heap.push_back(v[i]);
 	 			heap_size++;
 	 		}
 	 		for(int i=(n-1)/2;i>=0;i--)
 	 			heapify(i);
 	 	}
 		// insert a value to the heap
 		template<class T>
 		void MinPriorityQueue<T>::insert(const T& a)
 	 	{
 	 		
 	 		heap_size=heap_size+1;
 	 		heap[heap_size-1]=a;
 	 		heap_decrease_key(heap_size-1);
 	 		//this->print();
 	 	}
 		// get the minimum element from the heap
 		template<class T>
 		inline T MinPriorityQueue<T>::minimum()
 	 	{
 	 		return heap[0];
 	 	}
 		// return the minimum element from the heap and remove it
 		// as well
 		template<class T>
 		T MinPriorityQueue<T>::extract_min()
 	 	{
		T min = heap[0];
		//cout<<heap_size;
		heap[0] = heap[heap_size-1];
		heap_size=heap_size-1;
		heapify(0);
		return min;	 
 	 	}
 		// return the heap size
 		template<class T>
 		inline int MinPriorityQueue<T>::size()
 	 	{
 	 		return heap_size;
 	 	}
 		// build a heap from elements of a seqLinearList container 
 		template<class T>
 		void MinPriorityQueue<T>::build_heap(LinearList<T> v)
 	 	{
 	 		int n=v.size();
 	 		//if(n>heap.size()) heap.resize(n);
 	 		heap_size=0;
 	 		for(int i=0;i<n;i++)
 	 		{
 	 			heap.push_back(v[i]);
 	 			heap_size++;
 	 		}
 	 		for(int i=(n-1)/2;i>=0;i--)
 	 		{
 	 			heapify(i);
 	 		}

 	 	}
 		template<class T>
 		inline bool MinPriorityQueue<T>::empty()
 	 	{
 	 		if(heap_size==0) return true;
 	 		else return false;
 	 	}
 		// heap_decrease_key function
 		template<class T>
 		void MinPriorityQueue<T>::heap_decrease_key(const size_t& pos)
 	 	{
 	 		int i=pos;
 	 		T tmp;
 	 		while(i>0&&heap[i]<heap[parent(i)])
 	 		{
 	 	// 		tmp=heap[parent(i)];
				// heap[parent(i)]=heap[i];
				// heap[i]=tmp;
				swap(heap[parent(i)],heap[i]);
				i=parent(i); 	 			
 	 		}
 	 	}
 	 }

 	 		template<class T>
		void MinPriorityQueue<T>::print()
		{
			//cout<<endl;
			//cout<<heap_size;
			cout<<"Heap\n";
			for(int i=0;i<heap_size;i++)
			{
				cout<<" ["<<i<<"] "<<heap[i]<<endl;
			}

		}
#endif 