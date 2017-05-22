#ifndef PAIR_LIST
#define PAIR_LIST 1
class twin{
public:
    int first,second,third;
    twin()
    {
        
    }
    void set_parameters(int f,int s)
    {
        first=f;
        second=s;
    }
    inline bool operator < (twin rhs)
    {
        return this->first < rhs.first;
    }
    inline bool operator > (twin rhs)
    {
        return this->first > rhs.first;
    }
    int get_first()
    {
        return first;
    }
    int get_second()
    {
        return second;
    }
};
#endif