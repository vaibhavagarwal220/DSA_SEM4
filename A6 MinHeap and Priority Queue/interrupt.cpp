#include "device.hpp"
#include "MinPriorityQueue.hpp"
#include <limits.h>
int main()
{
	int n,id,burst_time,delay,priority,cpu_priority=10,current_time=0;
	
	cout<<"Enter Number of I/O Devices : ";
	cin>>n;

	Device temp;
	int reqTime[n];
	LinearList<Device> a(n);
	MinPriorityQueue<Device> interrupt;
	
	for(int i=0;i<n;i++)
	{
	cout<<"Enter DeviceID["<<i+1<<"] :";
	cin>>id;
	cout<<"Enter Burst Time["<<i+1<<"] :";
	cin>>burst_time;
	cout<<"Enter Delay["<<i+1<<"] :";
	cin>>delay;
	cout<<"Enter (0-9)Priority["<<i+1<<"] :";
	cin>>priority;
	if(i==0) {reqTime[0]=delay;}
	else reqTime[i]=reqTime[i-1] + delay;
	temp.setDevice(id,burst_time,delay,priority);
	a.push_back(temp);
	//a[i].viewDevice();
	}
	
	//reqTime[n]=INT_MAX;

	//interrupt.insert(a[0]);
	int cur_index=1;
	int flag=1;
	//int remTime=a[0].BurstTime();
	cout<<"\nISR for "<<a[0].DeviceID()<<" Started."<<endl;
	temp=a[0];
	
	cpu_priority=a[0].Priority();

	while(cur_index < n)
	{
			
			if(temp.BurstTime() != 0)
			cpu_priority = temp.Priority();
			else{
			cpu_priority = 10;
			//cout<<"ISR for "<<temp.DeviceID()<<" Ended."<<endl;
			}
		
		
		
		if(current_time == reqTime[cur_index])
		{
			cout<<"\nInterrupt by : "<<a[cur_index].DeviceID()<<endl;
			cout<<"Current CPU Priority : "<<cpu_priority<<"\n";
			cout<<"New Interrupt Priority : "<<a[cur_index].Priority()<<endl;
			if(cpu_priority > a[cur_index].Priority())
			{	
				 if(temp.BurstTime()!=0) interrupt.insert(temp);
				 //else {cout<<"ISR for "<<temp.DeviceID()<<" Ended.\n"<<endl;}
				 
				//cout<<"ISR for "<<temp.DeviceID()<<" Pre-empted."<<endl;
				temp = a[cur_index];
				cpu_priority = temp.Priority();
				//cout<<temp.BurstTime()<<endl;
				cout<<"New ISR Started\n\n";
				//cout<<"ISR for "<<temp.DeviceID()<<" started.\n"<<endl;
			}
			else
			{
				cout<<"Continuing old task\n";
				interrupt.insert(a[cur_index]);
			}
			cur_index++;
		}
		if(temp.BurstTime() == 0)
		{

			if(!interrupt.empty())
			{

				//cout<<"ISR for "<<temp.DeviceID()<<" Ended.\n"<<endl;
				temp = interrupt.extract_min();
				cpu_priority = temp.Priority();
				//cout<<"ISR for "<<temp.DeviceID()<<" started.\n"<<endl;
			}
			else
			{
				//temp.setBurstTime(0);
				//if(flag) cout<<"ISR for "<<temp.DeviceID()<<" Ended.\n"<<endl;
				cpu_priority = 10;
				flag=0;
				current_time++;
				if(flag) cout<<"Current Time : "<<current_time<<"\t"<<"ISR : "<<temp.DeviceID()<<endl;
				else {cout<<"Current Time : "<<current_time<<"\t"<<"ISR : No Interrupts"<<endl;}
				continue;
			}
		}
		temp.setBurstTime(temp.BurstTime() - 1);
		current_time ++;
		cout<<"Current Time : "<<current_time<<"\t"<<" ISR : "<<temp.DeviceID()<<endl;

	}

	while(temp.BurstTime())
	{
		temp.setBurstTime(temp.BurstTime() - 1);
		current_time++;
		cout<<"Time : "<<current_time<<"\t"<<"ISR : "<<temp.DeviceID()<<endl;
	}
cout<<"\n\n";
	while(!interrupt.empty())
	{
		temp=interrupt.extract_min();

		for(int i=temp.BurstTime();i>0;i--)
		{
		current_time++;
		cout<<"Time : "<<current_time<<"\t"<<"ISR : "<<temp.DeviceID()<<endl;
		}
		cout<<"\n";
		
	}

	cout<<"End"<<endl;

	return 0;
}