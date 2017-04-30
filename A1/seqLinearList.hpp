#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
              	int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
//		LinearList()
//		{
//
//			len=0;
	//		cout<<"Created an empty list";
		//}

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
				element=new Item[MaxListSize];
				len=0;
				MaxSize=MaxListSize;
				cout<<"Created list of Maximum Size "<<MaxSize<<endl;
		}

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
				cout<<"freeing memory"<<endl;
		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)
		{
			return element[i];
		} //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if(len==0) return true;
			else return false;
		}

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
			return len;
		}

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return MaxSize;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			if(k<=len && k>0) return element[k-1];
			else return 0;
		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
			if(k>len||k<=0) return false;
			else {x=element[k-1];return true;} 
		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int search(Item& x)
		{
			
			for(int i=0;i<len;i++)
			{
				if(element[i]==x) {return i+1;}
			}
			return 0;
		}

		void print()
		{
			cout<<endl;
			for(int i=0;i<len;i++)
			{
				cout<<element[i]<<endl;
			}

		}

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void deleteElement(const int  k, Item& x)
		{
			if(len>0&&k>0&&k<=len)
			{
				x=element[k-1];
				for(int i=k;i<len;i++)
					{
					element[i-1]=element[i];
					}
				len--;
				cout<<"deleted "<<x<<endl;
			}
			else {cout<<"empty list / out of bounds";}
		}

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x)
		{
			if(k>len||k<0) {cout<<"Out of Bounds"<<endl; return;}
			else if(len==MaxSize) {cout<<"Array completely filled"<<endl; return;}
			else if(len==0) {*element=x;len=1;cout<<"inserted "<< x <<endl;return;}
			else 
				{   	
					for(int i=len-1;i>=k;i--)
					{

						element[i+1]=element[i];
					}
					element[k]=x;

					len++;
					cout<<"inserted "<<x<<endl;
					return;
				}
		}
};


#endif
