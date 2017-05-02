#include "Undirected/UndirectedGraph.hpp"
#include <cstdlib>
void work(int& i)
 {
//cout<<" "<<i<<" ";
 }

int main(int argc, char *argv[])
{
  srand(time(NULL));
  bool not_found=false;
  int n,m,num_x,src,dest;
  pair<int,int> s,d,x;
  int dirx[]={-1,0,1};
  int diry[]={0,1,-1};
  cout<<"Enter Number of rows : ";
  cin>>n;
  cout<<"Enter number of columns : ";
  cin>>m;

  cout<<"Enter Source X coordinate : ";
  cin>>s.first;
  cout<<"Enter Source Y coordinate : ";
  cin>>s.second;
  cout<<"Enter Destination X coordinate : ";
  cin>>d.first;
  cout<<"Enter Destination Y coordinate : ";
  cin>>d.second;


  char a[n+2][m+2];
  UndirectedGraph g(n*m , 'l');
  
  for(int i=0;i<m+2;i++)
      {
        a[0][i]='X';  
        a[m+1][i]='X';
        a[i][0]='X';
        a[i][m+1]='X';
      }
  
  for(int i=1;i<=n;i++)
      {
      for(int j=1;j<=m;j++)
        a[i][j]='O';
      }



  cout<<"Enter Number of cells which cannot be visited : ";
  cin>>num_x;
  for(int i=0;i<num_x;i++)
      {
        cout<<"Enter X coordinate["<<i+1<<"] : ";
        cin>>x.first;
        cout<<"Enter Y coordinate ["<<i+1<<"] : ";
        cin>>x.second;
        if(x.first<=n&&x.first>=1 && x.second<=n&&x.second>=1)
          a[x.first][x.second]='X';
      }

         cout<<endl;
    for(int i=1;i<=n;i++)
      {
      for(int j=1;j<=m;j++)
           cout<<a[i][j]<<" ";
         cout<<endl;
      }

      for(int i=n;i>=1;i--)
      {
      for(int j=m;j>=1;j--)
          {

            if(a[i][j]=='O') 
            {
                int sx=rand()%3,sy=rand()%3;
                for(int k=sx;k<sx+3;k++)
                  for(int l=sy;l<sy+3;l++)
                    {
                      if(k%3==1 && l%3 == 1) continue;
                      int d1=i+dirx[k%3];
                      int d2=j+diry[l%3];
                      if(a[d1][d2]=='O') 
                      {
                        //if((i-1)*m +(j-1) == (d1 - 1)*m + (d2 - 1))
                          //continue;
                        g.add( (i-1)*m +(j-1) , (d1 - 1)*m + (d2 - 1) );
                      }

                    }
                /*pair<int,int> left = make_pair(i,j-1);
                pair<int,int> right = make_pair(i,j+1);
                pair<int,int> up = make_pair(i-1,j);
                pair<int,int> down = make_pair(i+1,j);
                pair<int,int> left_up = make_pair(i-1,j-1);
                pair<int,int> right_up = make_pair(i-1,j+1);
                pair<int,int> left_down = make_pair(i+1,j-1);
                pair<int,int> right_down = make_pair(i+1,j+1);

                if(a[left.first][left.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1) , (left.first - 1)*m + (left.second - 1) );
                }
                if(a[right.first][right.second]=='O') 
                {
                   g.add(  (i-1)*m +(j-1) , (right.first - 1)*m + (right.second - 1));
                }
                if(a[up.first][up.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1), (up.first - 1)*m + (up.second - 1));
                }
                if(a[down.first][down.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1),(down.first - 1)*m + (down.second - 1));
                }
                if(a[left_up.first][left_up.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1) , (left_up.first - 1)*m + (left_up.second - 1));
                }
                if(a[right_up.first][right_up.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1),(right_up.first - 1)*m + (right_up.second - 1));
                }
                if(a[left_down.first][left_down.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1),(left_down.first - 1)*m + (left_down.second - 1));
                }
                if(a[right_down.first][right_down.second]=='O') 
                {
                    g.add( (i-1)*m +(j-1),(right_down.first - 1)*m + (right_down.second - 1));
                } 
*/
            } 
          
//          cout<<endl;
          }

  //       cout<<endl;
      }
      src=(s.first-1)*m + (s.second-1);
      dest=(d.first-1)*m + (d.second-1);
      g.print();
      LinearList<DFSNode> arr(n*m);
      arr=g.dfs(work,dest);
    /*  LinearList< list<int> > predetree(n*m);
      for(int i=0;i<n*m;i++){
      	if(arr[i].pred!=-1) predetree[arr[i].pred].append(i);
      		}
		cout<<endl;
      for(int i=0;i<n*m;i++)
      	{
      	cout<<i<<" : ";
		predetree[i].print();
		cout<<endl;
		} */     	
    int tmp=src;
      //cout<<tmp;
      while(tmp!=-1)
      {
        cout<<" ("<<tmp/m + 1 <<","<<tmp%m + 1<<") = >";
        //cout<<tmp<<endl;
        if(tmp == dest) break;
        tmp=arr[tmp].pred;
        if(tmp==-1) {not_found=true;break;}
      }

      if(not_found) cout<<"\n No path found\n";
      cout<<" END\n";

	return 0;
}
