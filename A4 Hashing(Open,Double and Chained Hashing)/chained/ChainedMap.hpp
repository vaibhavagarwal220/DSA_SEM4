#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
#include "Dictionary.hpp"
using namespace cs202;
namespace cs202
{
template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{
	void rehash();
public:
	ChainedMap();
    ChainedMap(const int& num);
	ChainedMap(ChainedMap<Key, Value>& ht);
	~ChainedMap();
	Value& operator[](const Key& key);
    bool has(const Key& key);
    bool remove(const Key& key);
    Value get(const Key& key);
    void put(const Key& key, const Value& value);
    void prin();
};

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap()
{
    this->hashTable.resize(103);
    this->mod = 103;
    this->exist.resize(103);
    for(int i=0;i<103;i++)
        this->exist[i] = 0;
    this->size = 0;   
}

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(const int& num)
{
    this->hashTable.resize(num);
    this->mod = num;
    this->exist.resize(num);
    for(int i=0;i<num;i++)
        this->exist[i] = 0;
    this->size = 0;
}

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(ChainedMap<Key, Value>& ht)
{
    this->hashTable.resize(ht.mod);
    this->exist.resize(ht.mod);
    this->mod = ht.mod;
    for(int i=0;i<this->mod;i++)
    {
        this->hashTable[i] = ht.hashTable[i];
        this->exist[i] = ht.exist[i];
    }
    this->size = ht->size;
    
}

template<class Key, class Value>
ChainedMap<Key,Value>::~ChainedMap()
{
    this->hashTable.~LinearList();
}

template<class Key, class Value>
Value& ChainedMap<Key,Value>::operator[](const Key& key)
{
    int ind = this->hash(key);
    if(this->exist[ind]) 
    {
    listnode<pair<Key,Value> > *tmp=this->hashTable[ind].first;
    while ( tmp!= NULL )    
    {   
        if((tmp->data).first == key) return (tmp->data).second;  
    }
    return (Value)false;
    }
    else return (Value)false;
}

template<class Key, class Value>
bool ChainedMap<Key,Value>::has(const Key& key)
{
    int ind = this->hash(key);
    if(this->exist[ind]) 
    {
    listnode<pair<Key,Value> > *tmp=this->hashTable[ind].first;
    while ( tmp!= NULL )    
    {   
        if((tmp->data).first == key) return true;  
    }
    return false;
    }
    else return (Value)false;
}

template<class Key, class Value>
bool ChainedMap<Key,Value>::remove(const Key& key)
{
    int ind = this->hash(key);
    if(this->exist[ind])
    { 
        this->hashTable[ind].remove(make_pair(key,0));
        if(this->hashTable[ind].length()==0) this->exist[ind]=0;
        this->size--;
        return (Value)true;
    }
    else return (Value)false;
       
           
}

template<class Key, class Value>
Value ChainedMap<Key,Value>::get(const Key& key)
{
    int ind = this->hash(key);
    if(this->exist[ind]) 
    {
    listnode<pair<Key,Value> > *tmp=this->hashTable[ind].first;
    while ( tmp!= NULL )    
    {   
        if((tmp->data).first == key) return (tmp->data).second;  
    }
    }
}

template<class Key, class Value>
void ChainedMap<Key,Value>::put(const Key& key, const Value& value)
{
    int ind = this->hash(key);
    this->hashTable[ind].append(make_pair(key,value));
    this->exist[ind] = 1;
    this->size++;
    //cout<<"Inserted";
}

template<class Key, class Value>
void ChainedMap<Key,Value>::prin()
{
    for(int i=0;i<this->mod;i++)
    {
        if(this->exist[i] == 1)
            {this->hashTable[i].print();
            cout<<endl;}
    }    
}


}


#endif /* CHAINEDMAP_HPP_ */