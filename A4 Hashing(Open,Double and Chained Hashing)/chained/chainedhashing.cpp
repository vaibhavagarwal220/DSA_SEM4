#include "ChainedMap.hpp"
using namespace cs202;

int main()
{
	ChainedMap<int,int> a;

	int c;
	while(1)
	{
		cout<<"1.Insert\n";
		cout<<"2.Search\n";
		cout<<"3.Delete\n";
		cout<<"4.Print\n";
		cout<<"5.Exit\n";

		cout<<"\nEnter your choice : ";
		cin>>c;

		int key,value;
		switch(c)
		{
		case 1:
			cout<<"Enter key : ";
			cin>>key;
			cout<<"Enter value : ";
			cin>>value;
			a.put(key,value);
    		break;
		case 2:
			cout<<"Enter key to be searched : ";
			cin>>key;
			value = a.get(key);
			if(value)
				cout<<"Value at key "<<key<<" : "<<value<<endl;
			else
				cout<<"Key Not Found \n";
	    	break;
		case 3:
			cout<<"Enter key to be deleted : ";
			cin>>key;
			if(a.remove(key))
				cout<<"Key Deleted\n";
			else
				cout<<"Key Not Found\n";
		    break;
		case 4:
			a.prin();
			cout<<endl;
	    	break;
		default:
			return 0;
		}

	}
	return 0;
}