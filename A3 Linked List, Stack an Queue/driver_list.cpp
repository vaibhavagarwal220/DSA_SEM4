#include "list.hpp"
using namespace cs202;
int main()
{
	list<int> a;

	int b,c;
	while(1){
		cout<<"1.Insert at End\n2.Insert At Beginning\n3.Remove a value\n4.Size\n5.Check for empty\n6.Print\n7.Exit\nlist<<";
		cin>>b;
		switch(b)
		{
			case 1:cout<<"Enter value:";
					cin>>c;
					a.append(c);
					break;

			case 2:cout<<"Enter value:";
					cin>>c;
					a.cons(c);
					break;

			case 3:cout<<"Enter value:";
					cin>>c;
					a.remove(c);
					break;

			case 4:cout<<a.length()<<endl;
					break;

			case 5:if(a.empty()) cout<<"True\n";
					else cout<<"\nFalse\n";
					break;

			case 6:a.print();break;
			case 7:return 0;
					break;


			default:cout<<"Incorrect Choice"<<endl;
					break;
		}
	}
return 0;	
}