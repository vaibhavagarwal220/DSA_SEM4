#ifndef STACK_HPP_
#define STACK_HPP_
#include <iostream>
#include "list.hpp"
namespace cs202
{
  template<typename T>
    class stack
    {
      private:
        list<T> *stacklist;
      public:
        /*
         * Constructs a new stack.
         */
        stack();
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t);
        /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        T pop();
        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        T top();
        /*
         * Returns the number of elements currently in the stack.
         */
        int size();
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        inline bool empty();
        /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
        ~stack();
    };
    template<typename T>
    stack<T>::stack()
    {
        stacklist=new list<T>();
    }
    template<typename T>
    stack<T>::~stack()
    {
        delete stacklist;
    }
    template<typename T>
    void stack<T>::push(const T& t)
    {
        stacklist->cons(t);
    }
    template<typename T>
    int stack<T>::size()
    {
        return stacklist->length();
    }
    template<typename T>
    inline bool stack<T>::empty()
    {
        return stacklist->empty();
    }
     template<typename T>
     T stack<T>::pop()
     {
        T value=stacklist->head->data;
        stacklist->head=stacklist->head->next;
        stacklist->len-=1;
        return value;

     }
    template<typename T>
    T stack<T>::top()
    {
        return stacklist->head->data;
    }
}

#endif