#include "MinPriorityQueue.hpp"
#include <cstdlib>
int main()
{   
    MinPriorityQueue<int> a;
    int d;
    int value;
    while(1)
    {
    
    cout<<"1.Insert a element.\n";
    cout<<"2.ExtractMin.\n";
    cout<<"3.Print Minimum Element.\n";
    cout<<"4.Print Size.\n";
    cout<<"5.Check If Queue is Empty.\n";
    cout<<"6.Print.\n";
    cout<<"7.Exit.\n";
    cout<<"MinPriorityQueue << ";
    cin>>d;
    switch(d)
    {
    

        case 1: 
                cout<<"Enter Value:";
                cin>>value;
                a.insert(value);
                break;
        case 2: 
                if(!a.empty())
                cout<<"\n"<<a.extract_min()<<"\n"<<endl;
                else 
                cout<<"\nQueue Empty\n"<<endl;
                break;
        case 3: 
                if(!a.empty())
                cout<<"\n"<<a.minimum()<<"\n"<<endl;
                else 
                cout<<"\nQueue Empty\n"<<endl;
                break;                
        case 4: 
                cout<<"\nSize = "<<a.size()<<"\n"<<endl;
                break;
        case 5: 
                if(!a.empty())
                cout<<"\nQueue Not Empty\n"<<endl;
                else 
                cout<<"\nQueue Empty\n"<<endl;
                break;
        case 6:
                a.print();
                break;
        case 7:
                return 0;
        default:
                cout<<"\nInvalid Choice\n"<<endl;
                break;                
    }
    }
    return 0;
}