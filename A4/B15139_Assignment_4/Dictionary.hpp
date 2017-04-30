
#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_
#include "seqLinearList.hpp"
#include <string>
#include <sstream>
using namespace cs202;
template<class Key, class Value>
class Dictionary
{
protected:
LinearList<pair<Key,Value> > hashTable;
LinearList<int> exist;
int size;
int mod;
int hash(const Key &key);
int offsetHash(const Key &key);
public:
	virtual ~Dictionary(){};
	virtual bool has(const Key& key) = 0;
	virtual bool remove(const Key& key) = 0;
	virtual Value get(const Key& key) = 0;
	virtual void put(const Key& key, const Value& value) = 0;
};

template<class Key, class Value>
int Dictionary<Key,Value>::hash(const Key &key)
{
    stringstream ss;
	ss << key;
	string strkey = ss.str();
	int size = strkey.size();
	int x = 41;
	int ind = strkey[0];
	for(int i=1;i<size;i++)
	{
		ind = (ind*x + strkey[i])%mod;
	}
	return ind%mod;
}

template<class Key, class Value>
int Dictionary<Key,Value>::offsetHash(const Key &key)
{
	stringstream ss;
	ss << key;
	string strkey = ss.str();
	int size = strkey.size();
	int x = 41;
	int ind = strkey[0];
	for(int i=1;i<size;i++)
	{
		ind = (ind*x + strkey[i])%(mod/2);
	}
	return (mod/2) - ind%(mod/2);
}


#endif /* DICTIONARY_HPP_ */
