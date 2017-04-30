/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * 
 */
#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
using namespace std;
namespace cs202
{   

template<class T>
class list;    

template<class T>
class listnode{
    friend class list<T>;
    private:
            T data;
            listnode *link;    
};

  template<class T>
    class list
    {
        private:
            listnode<T> *first;
            listnode<T> *last;
                int len;
      public:
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
        list();
        /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
        list(const list<T> & x);
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
        ~list();
        /*
         * adds value at the end of the list.
         */
        void append(const T& value);
        /*
         * Returns the length of the list.
         */
        inline int length();
        /*
         * Returns a boolean indicating whether the list is empty.
         */
        inline bool empty();
        /*
         * Adds a value to the front of the list.
         */
        void cons(const T& value);
        /*
         * Removes the first occurence of the value from list.
         */
        void remove(const T & x);
        void print();
        /*
         * Appends the given list x at the end of the current list.
         */
        void append(list<T>& x);
    };
    
    template<class T>
    list<T>::list(){
        first=NULL;
        last=NULL;
        len=0;
    }
    
    template<class T>
    list<T>::list(const list<T> & x)
    {    first=NULL;
         last=NULL;
        len=0;

         listnode<T> *tmp=x.first;
        while ( tmp!= NULL ) 
       
        {   
            this->append(tmp->data);
            tmp = tmp->link;
        }

    }
    
    template<class T>
    list<T>::~list()
    {
        listnode<T> *tmp;
        while (first) 
       
        {   tmp = first->link;
            delete first;
            first=tmp;
        }
        len=0;
    }
    
    
    template<class T>
    void list<T>::append(const T& value)
    {
        listnode<T>* newnode=new listnode<T>();
        newnode->data=value;
        newnode->link=NULL;
         listnode<T> *tmp = last;
    if ( tmp != NULL ) {

        last->link=newnode;
        last=newnode;
    len++;
    }
    else {
    first = last = newnode;
    len++;
    }

    }

     template<class T>
    void list<T>::print()
    {
         listnode<T> *tmp=first;
        while ( tmp!= NULL ) 
       
        {   
            cout<<tmp->data<<endl;
            tmp = tmp->link;
        }
    }
  

    template<class T>
    inline int list<T>::length(){
        return len;
    }

    template<class T>
    inline bool list<T>::empty()
    {
        if (len>0) return false;
        return true;
    }
    
    template<class T>
    void list<T>::cons(const T& value)
    {
        listnode<T>* newnode=new listnode<T>();
        newnode->data=value;
        newnode->link=NULL;
         listnode<T> *tmp = first;
         first=newnode;
         first->link=tmp;
         len++;
    }
    
        template<class T>
    void list<T>::remove(const T & x)
    {
        listnode<T> *tmp = first,*tmp2=NULL;
        if(tmp->data==x){
        	tmp = first->link;
            delete first;
            first=tmp;
            len--;
        }
        else{while (tmp->link!=NULL) 
       
        {   
            if(tmp->link->data==x) 
            {
                
                tmp2=tmp->link;
                tmp->link=tmp->link->link;
                if(tmp->link==NULL) last=tmp;
                delete tmp2;
                len--;
                return;
            }
            tmp = tmp->link;
        }
        return;}

    }

           template<class T>
    void list<T>::append(list<T>& x){

         listnode<T> *tmp=x.first;
        last->link=tmp;
        last=x.last;
        len=len+x.len;

    }



}

#endif