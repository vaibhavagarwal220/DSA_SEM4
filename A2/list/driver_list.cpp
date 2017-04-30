#include "seqLinearList.hpp"
using namespace cs202;
int main()
{
	int m,x,pos,sw,n;
	cout<<"Enter max no of elements:";
	cin>>m;
	cout<<"Enter actual no of elements:";
	cin>>n;


	LinearList<int> a(m);

	for(int i=0;i<n;i++)
	{	cout<<"Enter Element["<<i+1<<"]:";
		cin>>x;
		a.insert(i,x);
	}
	
	while(1)
		{
		cout<<"\n\nChoose one of the following options"<<endl;
		cout<<"1.Print list\n2.Insert an Element\n3.Delete an element(with position)\n4.Delete an element(with value)\n5.Exit\n";
		cout<<"\nLinearList << ";
		cin>>sw;
		switch(sw)
		{
			case 1:
					a.print();break;
			
			case 2:	
					cout<<"Enter Element : ";
					cin>>x;
					cout<<"Enter Position : ";
					cin>>pos;
					a.insert(pos,x);
					break;

			case 3:
					cout<<"Enter position of element to delete:";
					cin>>pos;
					a.erase_pos(pos);
					break;

			case 4:
					cout<<"Enter value of element to delete:";
					cin>>pos;
					a.erase(pos);
					break;


			case 5:

						return 0;
			
			default:cout<<"\n\nInvalid Choice\n"<<endl;break;

		}
	}
	
	/*
	
	
	cout<<"Enter a position in the list(to find the element at that position):";
	int p;
	cin>>p;

	if(a.returnListElement(p)) cout<<"element at index " << p << " is " << a.returnListElement(p)<<endl;
	else cout<<"out of bounds"<<endl;

	*/


	return 0;

}