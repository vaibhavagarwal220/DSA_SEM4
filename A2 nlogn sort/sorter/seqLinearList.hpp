#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;
namespace cs202{
template<class T>
class LinearList{
	private:
		unsigned int capacity_;
		T *buffer_;    // 1D dynamic array
        unsigned int size_;
	public:
	LinearList(const int& MaxListSize);
	LinearList(const int& isize, const T& ival);
	~LinearList();
	void push_back(const T& item);
	bool empty();
	unsigned int size();
	unsigned int capacity();
	void fill(const T& item);
	void resize(const int& n);
	int find(T& x);
	void print();
	void erase(const T&  item);
	void erase_pos(const int&  k);
	void  insert(const int& k, T& x);
	inline T& at(const int& k);
	inline T& operator[](const int& i);		

	};

		template<class T>
		LinearList<T>::LinearList(const int& MaxListSize)
		{
				buffer_=new T[MaxListSize];
				size_=0;
				capacity_=MaxListSize;
				//cout<<"Created list of Maximum Size "<<capacity_<<endl;
		}
		template<class T>
		LinearList<T>::LinearList(const int& isize, const T& ival)
		{
				buffer_=new T[isize];
				size_=0;
				capacity_=isize;
				fill(ival);
		}

		/* Destructor. 
		 * Must free all the memory contained by the list */
		template<class T>
		LinearList<T>::~LinearList()
		{
				//cout<<"freeing memory"<<endl;
			delete buffer_;
		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first buffer_;
     		 * L[1] to the second buffer_ and so on.
     		 * */
		template<class T>
		inline T& LinearList<T>::at(const int& k)
		{
			return buffer_[k];	
		}    

		template<class T>
		inline T& LinearList<T>::operator[](const int& i)
		{
			return buffer_[i];
		} //return i'th buffer_ of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		template<class T>
		void LinearList<T>::push_back(const T& item)
		{
			insert(size_,item);
		}   

		template<class T>
		bool LinearList<T>::empty()
		{
			if(size_==0) return true;
			else return false;
		}

		/* Returns the actual size_gth (number of buffer_s) in the list.
     		 * */
		template<class T>
		unsigned int LinearList<T>::size()
		{
			return size_;
		}

		/* Returns the maximum size of the list.
     		 * */
		template<class T>
		unsigned int LinearList<T>::capacity()
		{
			return capacity_;
		}

		/* Returns the k-th buffer_ of the list. 
		 * */
		template<class T>
		void LinearList<T>::fill(const T& item)
		{
			for(int i=0;i<size_;i++)
			{
				buffer_[i]=item;
			}
		}

		 template<class T>
		 void LinearList<T>::resize(const int& n)
		 {
		 	size_=n;
		 }

		 template<class T>
		int LinearList<T>::find(T& x)
		{
			
			for(int i=0;i<size_;i++)
			{
				if(buffer_[i]==x) {return i+1;}
			}
			return 0;
		}

		template<class T>
		void LinearList<T>::print()
		{
			cout<<endl;
			for(int i=0;i<size_;i++)
			{
				cout<<buffer_[i]<<endl;
			}

		}

		/* Set x to the k-th buffer_ and delete that k-th buffer_.
		 * */
		template<class T>
		void LinearList<T>::erase(const T&  item)
		{

				for(int i=0;i<size_;i++)
					{
					if(buffer_[i]==item) {erase_pos(i+1);}
					}
				
				//cout<<"deleted "<<x<<endl;
		
		}
		template<class T>
		void LinearList<T>::erase_pos(const int&  k)
		{

				for(int i=k;i<size_;i++)
					{
					buffer_[i-1]=buffer_[i];
					}
				size_--;
				//cout<<"deleted "<<x<<endl;
		
		}

		/* Insert x after k-th buffer_.
		 * */
		template<class T>
		void LinearList<T>::insert(const int& k, T& x)
		{
			if(size_==0) 
			{
			*buffer_=x;size_=1;
			//cout<<"inserted "<< x <<endl;
			return;
			}
			
			else 
				{   	
					for(int i=size_-1;i>=k;i--)
					{

						buffer_[i+1]=buffer_[i];
					}
					buffer_[k]=x;

					size_++;
					//cout<<"inserted "<<x<<endl;
					return;
				}
		}



}


#endif
