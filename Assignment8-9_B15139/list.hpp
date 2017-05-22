#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "queue"

namespace cs202
{
   template<class T>
    class Node
    {
    public:
         T data;
         Node *next;
    };
  template<class T>
    class list
    {
      public:
        Node<T> *head;
        Node<T> *tail;
        int len;
      // public:
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
      //  list(const list<T> & x);
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
      //  ~list();
        /*
         * adds value at the end of the list.
         */
        void append(const T& value);
        /*
         * Returns the length of the list.
       //  */
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
        /*
         * Appends the given list x at the end of the current list.
         */
    //    void append(list<T>& x);
        void print();
    };
    template<typename T>
    list<T>::list()
    {
        head=NULL;
        tail=NULL;
        len=0;
    }
     //template<typename T>
    // list<T>::list()
    // {
       
    // }
      template<typename T>
    void list<T>::append(const T& value)
    {
        Node<T> *newnode=new Node<T>;
        newnode->data=value;
        if(tail==NULL)
        {
             newnode->next=head;
             head=newnode;
             tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        len++;
    }
    template<typename T>
    inline bool list<T>::empty()
    {
        if(head==NULL)
            return true;
        return false;
    }
    template<typename T>
    void list<T>::cons(const T& value)
    {
         Node<T> *newnode=new Node<T>;
         newnode->data=value;
         newnode->next=head;
         head=newnode;
         len++;
    }
     template<typename T>
    void list<T>::print()
    {
        Node<T> *temp=head;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<std::endl;
            temp=temp->next;
        }
    }
    template<typename T>
    inline int list<T>::length()
    {
        return len;
    }
    template<typename T>
    void list<T>::remove(const T & x)
    {
        Node<T> *temp=head;
        if(temp->data==x)
        {
            head=temp->next;
            len--;
            return;
        }
        while(temp!=NULL)
        {
            if((temp->next)->data==x)
            {
                if(temp->next->next==NULL)
                    tail=temp;
                temp->next=temp->next->next;
                len--;
                break;
            }
            temp=temp->next;
        }
    }
}

#endif