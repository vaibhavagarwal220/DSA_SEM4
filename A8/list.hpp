#ifndef LIST_HPP
#define LIST_HPP 1   

template<class T>
class list;

    

/*template<class T>
class listnode{
    friend class list<T>;
    public:
            T data;
            listnode *link;

};
*/
  template<class T>
    class list
    {
        public:  
            listnode<T> *init;
            listnode<T> *last;
                int len;

        list();
        list(const list<T> & x);
        ~list();
        void append(const T& value);
        inline int length();
        inline bool empty();
        void cons(const T& value);
        void remove(int x);
        //void print();
        void append(list<T>& x);
        bool find(int val);
        listnode<T>* getfirst()
        {
            return init;
        }        
    };
    
    template<class T>
    list<T>::list(){
        init=NULL;
        last=NULL;
        len=0;
    }
    
    template<class T>
    list<T>::list(const list<T> & x)
    {    init=NULL;
         last=NULL;
        len=0;

         listnode<T> *tmp=x.init;
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
        while (init) 
       
        {   tmp = init->link;
            delete init;
            init=tmp;
        }
        len=0;
    }
    
    
    template<class T>
    void list<T>::append(const T& value)
    {
        listnode<T>* newnode=new listnode<T>();
        newnode->data=value;
        //cout<<(newnode->data).init;
        //cout<<(newnode->data).second;
        newnode->link=NULL;
         listnode<T> *tmp = last;
    if ( tmp != NULL ) {

        last->link=newnode;
        last=newnode;
    len++;
    }
    else {
    init = last = newnode;
    len++;
    }
    
    }

    /* template<class T>
    void list<T>::print()
    {
        listnode<T> *tmp=init;
        while ( tmp!= NULL )        
        {   
            cout<<(tmp->data).first<<" ("<<(tmp->data).second<<") ";
            tmp = tmp->link;
        }
    }*/

    template<class T>
    bool list<T>::find(int val)
    {
        listnode<T> *tmp=init;
        while ( tmp!= NULL ) 
       
        {   
            if(val==(tmp->data).first) {return true;}
            tmp = tmp->link;
        }
        return false;

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
         listnode<T> *tmp = init;
         init=newnode;
         init->link=tmp;
         len++;
    }
    
        template<class T>
    void list<T>::remove(int x)
    {
        listnode<T> *tmp = init,*tmp2=NULL;
        if((tmp->data).first==x){
        	tmp = init->link;
            delete init;
            init=tmp;
            len--;
        }
        else{while (tmp->link!=NULL) 
       
        {   
            if((tmp->link->data).first==x) 
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

         listnode<T> *tmp=x.init;
        last->link=tmp;
        last=x.last;
        len=len+x.len;

    }




#endif