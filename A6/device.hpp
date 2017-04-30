#ifndef DEVICE_HPP
#define DEVICE_HPP
#include <iostream>
#include <string.h>

using namespace std;
namespace cs202{

class Device{
	private:
		int id;
		int burstt;
		int delayt;
		int priority;
	public:

	Device()
	{

	}

	inline int DeviceID()
	{
		return id;
	}
	inline int BurstTime()
	{
		return burstt;
	}
	inline int setBurstTime(int bt)
	{
		this->burstt=bt;
	}
	inline int Delay()
	{
		return delayt;
	}
	inline int Priority()
	{
		return priority;
	}
	inline int setDevice(int id,int burst,int delay,int pri)
	{
		this->id=id;
		this->burstt=burst;
		this->delayt=delay;
		this->priority=pri;
	}
	inline int viewDevice()
	{
		cout<<"\n Device ID : "<<this->id<<"\n Burst Time : "<<this->burstt<<"\n Delay:"<<this->delayt<<"\n Priority : "<<this->priority<<"\n"<<endl;
	}
	inline bool operator < (Device rhs)
	{
		return this->priority < rhs.Priority();
	}
	inline bool operator > (Device rhs)
	{
		return this->priority > rhs.Priority();
	}		

	};
		

		
}


#endif
