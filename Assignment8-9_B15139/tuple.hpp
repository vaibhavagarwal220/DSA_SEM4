#ifndef TUPLE_LIST
#define TUPLE_LIST 1
class tuple{
public:
    int first,second,third;
    tuple()
    {
        
    }
    void set_parameters(int f,int s,int t)
    {
        first=f;
        second=s;
        third=t;
    }
    inline bool operator < (tuple rhs)
    {
        return this->first < rhs.first;
    }
    inline bool operator > (tuple rhs)
    {
        return this->first > rhs.first;
    }
};
#endif