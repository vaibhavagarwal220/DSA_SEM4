#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <string.h>
#include <stdlib.h>
namespace cs202 {
    template<typename T>
    class LinearList{
      private:
        T* buffer_;
        unsigned int size_;
        unsigned int capacity_;
      public:
        // Default Constructor
        // Creates a zero sized LinearList
        LinearList();

        // Constructor with size as input
        LinearList(const int& isize);                   

        // Constuctor with size and default value as input
        LinearList(const int& isize, const T& ival);    

        // Default Destructor
      //  ~LinearList();                                  

        // Accessing an element of the LinearList using operator
        /*inline*/ T& operator[](const int& i);         

        // Return the element in the list at position k
        /*inline*/ T& at(const int& k);         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const T& item);              

        // Returns true if LinearList is empty
        bool empty();                               

        // Returns the size of the LinearList
        unsigned int size();                                 

        // Returns the capacity of the LinearList
        unsigned int capacity();                                 

        // Fills all the elements with a default value
        void fill(const T& item);                   

        // Resizes the LinearList
        void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const T& item);

        // Remove all occurences of an item in the list
        void erase(const T& item);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

        // Insert item at position k
        void insert(const T& item, const int& k);

        // Iterator class for LinearList
        // This should be used to traverse the LinearList
        // See std::vector<T>::iterator for more understanding
        // on how iterators work
        class iterator{                             
          private:
            T* elem_;
          public:
            iterator();
            iterator(T* ptr);
            ~iterator();
            T& operator*();
            void operator=(T *ptr);
            void operator=(iterator iter);
            void operator++();
            void operator--();
            bool operator!=(T* ptr);
            bool operator==(T* ptr);
            bool operator!=(iterator iter);
            bool operator==(iterator iter);
            iterator operator+(int i);
            iterator operator-(int i);
        };
        iterator begin();                       
        iterator end();
  };
  template<typename T>
LinearList<T>::LinearList()
{
    capacity_=1000;
    buffer_=new T[capacity_];
   // memset(buffer_,0,sizeof(capacity_));
    size_=0;   
}
template<typename T>
LinearList<T>::LinearList(const int& isize)
{
    capacity_=isize;
    buffer_=new T[capacity_];
   // memset(buffer_,0,sizeof(capacity_));
    size_=0;
}
template<typename T>
LinearList<T>:: LinearList(const int& isize, const T& ival)
{
    capacity_=size_=isize;
    buffer_=new T[capacity_];
    memset(buffer_,ival,isize);
}
template<typename T>
T& LinearList<T>::operator[](const int& i)
{
    return buffer_[i];
}
template<typename T>
T& LinearList<T>::at(const int& k)
{
    return buffer_[k];
}
template<typename T>
void LinearList<T>::push_back(const T& item)
{
    if(size_+1>capacity_)
    {
        capacity_*=2;
        T *temp=new T[capacity_];
        for(int i=0;i<size_;i++)
            temp[i]=buffer_[i];
        delete buffer_;
        buffer_=temp;
      //  buffer_=(T*)realloc(buffer_,capacity_);
    }
    buffer_[size_]=item;
    size_++;
}
template<typename T>
bool LinearList<T>::empty()
{
   if(size_==0)
    return true;
return false;
}
template<typename T>
unsigned int LinearList<T>::size()
{
    return size_;
}
template<typename T>
unsigned int LinearList<T>::capacity()
{
    return capacity_;
}
template<typename T>
void LinearList<T>::fill(const T& item)
{
    memset(buffer_,item,size_);
}
template<typename T>
void LinearList<T>::resize(const int& n)
{
    if(n>size_)
    {
        if(n>capacity_)
        {
            capacity_*=2;
            //buffer_=(T*)realloc(buffer_,capacity_);
        T *temp=new T[capacity_];
        for(int i=0;i<size_;i++)
            temp[i]=buffer_[i];
        delete buffer_;
        buffer_=temp;
        }
        // for(int i=size_;i<n;i++)
        //     buffer_[i]=0;
    }
     size_=n;
    
}
template<typename T>
int LinearList<T>::find(const T& item)
{
    for(int i=0;i<size_;i++)
    {
        if(buffer_[i]==item)
            return i;
    }
    return size_;
}


template<typename T>
void LinearList<T>::erase_pos(const int& pos)
{
    for(int i=pos+1;i<size_;i++)
    {
        buffer_[i-1]=buffer_[i];
    }
    size_--;
}
template<typename T>
void LinearList<T>::insert(const T& item, const int& k)
{
        if(size_+1>capacity_)
        {
        capacity_*=2;
        T *temp=new T[capacity_];
        for(int i=0;i<size_;i++)
        temp[i]=buffer_[i];
        delete buffer_;
        buffer_=temp;
        }
    for(int i=size_-1;i>=k;i--)
    {
        buffer_[i+1]=buffer_[i];
    }
    buffer_[k]=item;
    size_++;
}
template<class T>
        void LinearList<T>::erase(const T&  item)
        {

                for(int i=0;i<size_;i++)
                    {
                    if(buffer_[i]==item) {erase_pos(i+1);}
                    }
                
        }
// template<typename T>
// LinearList<T>::iterator::iterator()
// {
//     elem_=buffer_;
// }
// template<typename T>
// LinearList<T>::iterator::iterator(T* ptr)
// {
//     elem_=ptr;
// }
// template<typename T>
// T& LinearList<T>::iterator:: operator*()
// {
//     return *elem_;
// }
// template<typename T>
// void LinearList<T>::iterator::operator=(T *ptr)
// {
//     elem_=ptr;
// }
// template<typename T>
// void LinearList<T>::iterator::operator++()
// {
//     elem_++;
// }

// template<typename T>
// void LinearList<T>::iterator::operator--()
// {
//     elem_--;
// }

// template<typename T>
// bool LinearList<T>::iterator::operator!=(T* ptr)
// {
//     return this.elem_!=ptr;
// }
// template<typename T>
// iterator LinearList<T>::iterator::begin()
// {
//     return iterator(elem_);
// }
// template<typename T>
// iterator LinearList<T>::iterator::end()
// {
//     return iterator(elem_+size);
// }
// template<typename T>
// iterator LinearList<T>::iterator::operator+(int i)
// {
//     return iterator(elem_+i);
// }
// template<typename T>
// iterator LinearList<T>::iterator::operator-(int i)
// {
//     return iterator(elem_-i);
// }
}
/***************Modifying***********************/
//using namespace cs202;
#endif  /* _SEQ_LINEAR_LIST */

