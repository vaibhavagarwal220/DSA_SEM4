#include "seqLinearList.hpp"
#include "sorting.hpp"
//#include "timer.hpp"
int main()
{
	clock_t start,stop;
	int m,x,pos,sw,n;
	double elapsed;
//	Timer T;
//	T.begin();
	cout<<"Enter max no of elements:";
	cin>>m;
	cout<<"Enter actual no of elements:";
	cin>>n;
	Sort<int> S;


	LinearList<int> a(m);

	for(int i=0;i<n;i++)
	{	cout<<"Enter Element["<<i+1<<"]:";
		cin>>x;
		a.insert(i,x);
	}
	
	while(1)
		{
		cout<<"\n\nChoose one of the following options"<<endl;
		cout<<"1.Print list\n2.Insert an Element\n3.Delete an element\n4.Show maximum size of list\n5.Show current length of the list\n6.Find element at a particular location\n7.Find position of an element\n8.Check if list is empty\n9.Rank Sort\n10.Bubble Sort\n11.Insertion Sort\n12.Selection Sort\n13.Exit\n";
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
					a.deleteElement(pos,x);
					break;

			case 4:
					cout<<" \n\nMaxSize of list is "<<a.maxSize()<<"\n"<<endl;
					
					break;
			
			case 5:
					cout<<"\n\nCurrent Length of list is "<<a.length()<<"\n"<<endl;
					break;
			

			case 6:
					cout<<"Enter a position in the list:";
					cin>>pos;

					if(a.find(pos,x)) cout<<"\n\n"<<"Element at index " << pos << " is " << x <<"\n"<<endl;
					else cout<<"\n\n"<<"Out of bounds"<<"\n"<<endl;

					break;
			
			case 7:
					cout<<"Enter value of the element:";
					cin>>x;

					if(pos=a.search(x)) cout<<" \n\n "<< x << " found at " << pos <<"\n"<<endl;
					else cout<<" \n\n "<< x << " not found in the list"<<"\n"<<endl;

					break;
			
			case 8:	
					if(a.isEmpty()) cout<<"Empty list"<<endl;
					else cout<<"\n\nList contains some elements"<<"\n"<<endl;
				   	break;
			
			case 9:
						start=clock();
						S.rankSort(a,1,a.length());
						stop=clock();
						elapsed=(double)(stop-start)/CLOCKS_PER_SEC;
						cout<<(double)elapsed<<" seconds taken"<<endl;
						a.print();
						
						
						break;
			
			case 10:
						start=clock();	
						S.bubbleSort(a,1,a.length());
						stop=clock();
						elapsed=(double)(stop-start)/CLOCKS_PER_SEC;
						cout<<(double)elapsed<<" seconds taken"<<endl;
						a.print();
						
						
						break;
			
			case 11:
						start=clock();	
						S.insertionSort(a,1,a.length());
						stop=clock();
						elapsed=(double)(stop-start)/CLOCKS_PER_SEC;
						cout<<(double)elapsed<<" seconds taken"<<endl;
						a.print();
						
						
						break;
			
			case 12:
						start=clock();	
						S.selectionSort(a,1,a.length());
						stop=clock();
						elapsed=(double)(stop-start)/(double)CLOCKS_PER_SEC;
						cout<<(double)elapsed<<" seconds taken"<<endl;

						a.print();
						
						
						break;
			

			case 13:
//						T.end();
//						T.display();
						return 0;
			
			default:cout<<"\n\nInvalid Choice\n"<<endl;return 0;break;

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