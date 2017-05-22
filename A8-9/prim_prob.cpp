#include "Undirected/UndirectedGraph.hpp"

using namespace std;

int main()
{
	int n,m,x,y,c,q,i,f=0,cnt=0;

	cout<<"Enter No of Locations : ";
	cin>>n;
	edge *mst;
	UndirectedGraph g(n,'l');
	cout<<"Enter No of Roads : ";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"Enter Road["<<i+1<<"] : ";
		cin>>x;
		cin>>y;
		cin>>c;
		g.add(x,y,c);
	}
	cout<<"Enter No of Questions : ";
	cin>>q;
	mst=g.prim();
	g.printMST();
	for(i=0;i<q;i++)
	{
		f=0;
		cout<<"Enter Question["<<i+1<<"] : ";
		cin>>x>>y;
		
		for(int j=0;j<n-1;j++)
		{
			if( (x==mst[j].src && y==mst[j].dest ) || (y==mst[j].src && x==mst[j].dest ) )
			{cout<<"yes"<<endl;f=1;cnt++;}

		}
		if(f==0) cout<<"no"<<endl;


	}
	cout<<"The Number of yes is "<<cnt<<endl;
	return 0;

}