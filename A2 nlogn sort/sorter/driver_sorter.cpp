#include "seqLinearList.hpp"
#include "sorting.hpp"
#include <stdlib.h>
#include "timer.hpp"
#include <fstream>
using namespace cs202;
int main(int argc, char const *argv[])
{	
	int m,x,pos,sw,n,ts;
	timer T;
	ofstream myfile;
 	myfile.open ("time.txt",ofstream::app);
	Sort<int> S;

	if(argc==2){
		ts=atoi(argv[1]);

	
	cin>>m;
	LinearList<int> a(m);
	
	for(int i=0;i<m;i++)
	{	
		cin>>x;
		a.insert(i,x);
	}


switch(ts)
		{
		
			case 1:		T.start();
						S.rankSort(a,1,a.size());
						T.stop();
						T.print();
						
  						myfile<<" "<<T.last_timing();
  						//a.print();
						
						
						break;
			
			case 2:		T.start();
						S.bubbleSort(a,1,a.size());
						T.stop();
						T.print();
						myfile<<" "<<T.last_timing();
						//a.print();

						
						
						break;
			
			case 3:		T.start();
						S.insertionSort(a,1,a.size());
						T.stop();
						T.print();
						myfile<<" "<<T.last_timing();
						//a.print();
						
						
						break;
			
			case 4:		T.start();
						S.selectionSort(a,1,a.size());
						T.stop();
						T.print();
						myfile<<" "<<T.last_timing();
						//a.print();
						
						
						break;
			case 5:		T.start();
						S.mergeSort(a,0,a.size()-1);
						T.stop();
						T.print();
						myfile<<" "<<T.last_timing();
						//a.print();
						
						
						break;			
			case 6:		T.start();
						S.quickSort(a,0,a.size()-1);
						T.stop();
						T.print();
						myfile<<" "<<T.last_timing();
						//a.print();
						
						
						break;					

			case 7:

						return 0;
			
			default:cout<<"\n\nInvalid Choice\n"<<endl;break;

		}
		myfile.close();
						

	}

	else if(argc==1){
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
		cout<<"1.Rank Sort\n2.Bubble Sort\n3.Insertion Sort\n4.Selection Sort\n5.Merge Sort\n6.Quick Sort\n7.Exit\n";
		cout<<"\nLinearList << ";
		cin>>sw;
		switch(sw)
		{
			/*case 1:
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
					a.erase_pos(pos,x);
					break;
			*/
			case 1:		T.start();
						S.rankSort(a,1,a.size());
						T.stop();
						T.print();
						a.print();
						
						
						break;
			
			case 2:		T.start();
						S.bubbleSort(a,1,a.size());
						T.stop();
						T.print();
						a.print();

						
						
						break;
			
			case 3:		T.start();
						S.insertionSort(a,1,a.size());
						T.stop();
						T.print();
						a.print();
						
						
						break;
			
			case 4:		T.start();
						S.selectionSort(a,1,a.size());
						T.stop();
						T.print();
						a.print();
						
						
						break;
			case 5:		T.start();
						S.mergeSort(a,0,a.size()-1);
						T.stop();
						T.print();
						a.print();
						
						
						break;			
			case 6:		T.start();
						S.quickSort(a,0,a.size()-1);
						T.stop();
						T.print();
						a.print();
						
						
						break;					

			case 7:
//						T.end();
//						T.display();
						return 0;
			
			default:cout<<"\n\nInvalid Choice\n"<<endl;return 0;break;

		}
	}
	}


	return 0;

}