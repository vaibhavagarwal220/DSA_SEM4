#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <iostream>
#include "list.hpp"
#include "queue"
namespace cs202
{
  template <typename T>
    class queue
    {
        private:
        list<T> *queuelist;
      public:
        /*
         * Constructs a new queue.
         */
        queue();
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t);
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        T pop();
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        T front();
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size();
        /*
         * Returns a boolean indicating whether the queue is empty or not.
         */
        inline bool empty();
        /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue();
    };
    template <typename T>
    queue<T>::queue()
    {
        queuelist=new list<T>();
    }
    template <typename T>
    queue<T>::~queue()
    {
        delete queuelist;
    }
    template<typename T>
    void queue<T>::push(const T& t)
    {
        queuelist->append(t);
    }
    template<typename T>
    inline int queue<T>::size()
    {
        return queuelist->length();
    }
    template<typename T>
    inline bool queue<T>::empty()
    {
        return queuelist->empty();
    }
    template<typename T>
    T queue<T>::front()
    {
        return queuelist->head->data;
    }
    template<typename T>
    T queue<T>::pop()
    {
         T value=queuelist->head->data;
        queuelist->head=queuelist->head->next;
        queuelist->len-=1;
        return value;
    }
}
#endif