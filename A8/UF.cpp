#include "UFDS.hpp"


int main()
{
	UFDS dis(5);
	for(int i=0;i<5;i++)
    	{
    		dis.make_set(i);
    	}
    	//cout<<dis.find_set(1);
     	//cout<<dis.find_set(2);
     	//dis.union_set(1,3);
     	dis.union_set(1,2);
     	dis.union_set(3,4);
     	//cout<<dis.find_set(1);
     	//cout<<dis.find_set(2);
     	//cout<<dis.find_set(3);
     	//cout<<dis.find_set(4);
     	cout<<dis.num_disjoint_sets()<<endl;
     	cout<<dis.size_set(1)<<endl;
     	cout<<dis.size_set(2)<<endl;
     	cout<<dis.size_set(3)<<endl;
     	cout<<dis.size_set(4)<<endl;
     	cout<<dis.size_set(5)<<endl;


	return 0;
}