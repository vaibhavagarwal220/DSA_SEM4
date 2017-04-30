#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_
#include "Dictionary.hpp"
using namespace cs202;
namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
{
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash()
    {


    int psize = this->mod;
    int p=1;
    int j , k;
    k=this->mod + 1;
    for(k;;k++)
    {
        p=1;
        for( j=2;j*j<k;j++)
        {
            if(k%j==0)
                p=0;
        }
        if(p==1)
        {
            break;
        }
    }
    //cout<<i;
    this->mod = k;
    LinearList<pair<Key,Value> > ntab ;
    LinearList<int> nexist ;
    //arraysize=arraysize*2;
    ntab.resize(this->mod);
    nexist.resize(this->mod);
    for(int i = 0 ;i<psize;i++)
    {
        ntab[i]=this->hashTable[i];
        nexist[i]=this->exist[i];
    }
    
    this->hashTable.resize(this->mod);
    this->exist.resize(this->mod);
    this->exist.fill(0);
    this->size=0;
    for(int i = 0 ;i<psize;i++)
    {
        if(nexist[i]==1)
            this->put(ntab[i].first,ntab[i].second);
    }



    }
public:
	DoubleHashMap();
	DoubleHashMap(const int& num);
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
	~DoubleHashMap();
	Value& operator[](const Key& key);
    bool has(const Key& key);
    bool remove(const Key& key);
    Value get(const Key& key);
    void put(const Key& key, const Value& value);
    void print();
};

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap()
{
    this->hashTable.resize(103);
    this->mod = 103;
    this->exist.resize(103);
    for(int i=0;i<103;i++)
        this->exist[i] = 0;
    this->size = 0;

}

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap(const int& num)
{
    this->hashTable.resize(num);
    this->mod = num;
    this->exist.resize(num);
    for(int i=0;i<num;i++)
        this->exist[i] = 0;
    this->size = 0;    
}

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap(DoubleHashMap<Key, Value>& ht)
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
DoubleHashMap<Key,Value>::~DoubleHashMap()
{
    this->hashTable.~LinearList();
    this->exist.~LinearList();
}

template<class Key, class Value>
Value& DoubleHashMap<Key,Value>::operator[](const Key& key)
{
    int ind = this->hash(key);
    int i = 0;
    int offset = this->offsetHash(key);
    while(this->exist[ind] && i < this->mod)
    {
        if(this->exist[ind] == -1 || this->hashTable[ind].first != key)
        {
            ind = (ind + offset) % this->mod;
            i++;
        }
        else
        {
            return this->hashTable[ind].second;
        }
    }
    if(i == this->mod || this->exist[ind] == 0)
    {
        return (Value)false;
    }
}

template<class Key, class Value>
bool DoubleHashMap<Key,Value>::has(const Key& key)
{
    int ind = this->hash(key);
    int i = 0;
    int offset = this->offsetHash(key);
    while(this->exist[ind] && i < this->mod)
    {
        if(this->exist[ind] == -1 || this->hashTable[ind].first != key)
        {
            ind = (ind + offset) % this->mod;
            i++;
        }
        else
        {
            return true;
        }
    }
    return  false;
}

template<class Key, class Value>
bool DoubleHashMap<Key,Value>::remove(const Key& key)
{
    int ind = this->hash(key);
    int i = 0;
    int offset = this->offsetHash(key);
    while(this->exist[ind] && i < this->mod)
    {
        if(this->exist[ind] == -1 || this->hashTable[ind].first != key)
        {
            ind = (ind + offset) % this->mod;
            i++;
        }
        else
        {
            this->exist[ind] = -1;
            this->size--;
            return true;
        }
    }
    return  false;
}

template<class Key, class Value>
Value DoubleHashMap<Key,Value>::get(const Key& key)
{
   int ind = this->hash(key);
    int i = 0;
    int offset = this->offsetHash(key);
    while(this->exist[ind] && i < this->mod)
    {
        if(this->exist[ind] == -1 || this->hashTable[ind].first != key)
        {
            ind = (ind + offset) % this->mod;
            i++;
        }
        else
        {
            return this->hashTable[ind].second;
        }
    }
}

template<class Key, class Value>
void DoubleHashMap<Key,Value>::put(const Key& key, const Value& value)
{
    int ind = this->hash(key);
    int i = 0;
    int offset =this->offsetHash(key);
    while(this->exist[ind] == 1 && i < this->mod)
    {
        if(this->hashTable[ind].first == key)
            break;
        ind = (ind + offset) % this->mod;
        
        i++;
    }
    if(i == this->mod)
    {
        cout<<"Hash Table full\n";
        this->rehash();
        return ;
    }
    this->exist[ind] = 1;
    this->size++;
    this->hashTable[ind] = make_pair(key,value);
}

template<class Key, class Value>
void DoubleHashMap<Key,Value>::print()
{
    for(int i=0;i<this->mod;i++)
    {
        if(this->exist[i] == 1)
            cout<<this->hashTable[i].first<<" "<<this->hashTable[i].second<<endl;
    }
}

}

#endif 