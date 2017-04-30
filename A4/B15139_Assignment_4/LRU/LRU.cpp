#include "OpenMap.hpp"
#include "seqLinearList.hpp"
using namespace std;
using namespace cs202;

#define ram_size 65536
#define cache_size 4
#define block_size 4
int main()
{
LinearList<int> ram;
ram.resize(ram_size);
for(int i=0;i<ram_size;i++)
    {
    ram[i]=i;
 //   cout<<ram[i]<<endl;
    }
    OpenMap<int,int> cache(cache_size);
    pair<int,int> cnt[cache_size];
    for(int i=0;i<cache_size;i++)
		cnt[i].second = -1;
int r;
do
{
cin>>r;
int ind=r/block_size;
if(cache.has(ind))
		{
			for(int i=0;i<cache_size;i++)
				if(cnt[i].second != -1)
					cnt[i].second++;
			cnt[cache.returnind(ind)].second = 0;
			cnt[cache.returnind(ind)].first = ind;
		}
else
    	{
			if(!cache.full())
			{
				cache.put(ind,ind);
				for(int i=0;i<cache_size;i++)
				{
					if(cnt[i].second != -1)
						cnt[i].second++;
				}
				cnt[cache.returnind(ind)].second = 0;
				cnt[cache.returnind(ind)].first = ind;
			}
			else
			{
				int remindex,max = -1;
				for(int i=0;i<cache_size;i++)
					if(max < cnt[i].second)
					{
						max = cnt[i].second;
						remindex = cnt[i].first;
					}
				cache.remove(remindex);
				

				cache.put(ind,ind);
				for(int i=0;i<cache_size;i++)
				{
					if(cnt[i].second != -1)
						cnt[i].second++;
				}
				cnt[cache.returnind(ind)].second = 0;
				cnt[cache.returnind(ind)].first = ind;
			}
		}

        cout<<"Counter State \n";
		for(int i=0;i<cache_size;i++)
			cout<<i<<" >> "<<cnt[i].first<<" "<<cnt[i].second<<endl;
		cout<<endl;

        cout<<"Cache state \n";
		for(int i=0;i<cache_size;i++)
		{
			cout<<"MMB "<<cache.key(i)<<" : "<<endl;
			if(cache.exist_(i))
			{
				for(int j=0;j<block_size;j++)
				{
					cout<<"Instruction "<<cache.value(i)*block_size + j<<endl;
				}
			}
		}
		cout<<endl<<endl;

}while(r>=0);
return 0;
}