#include "BSTree.hpp"
#include <cstdlib>
int main()
{
    BSTree<int,int> a;
    int c;
    int key,value;
    while(1)
    {
    //system("clear");
    cout<<"1.Insert a node into BST.\n";
    cout<<"2.Delete a node into BST.\n";
    cout<<"3.Print Pre-Order Traversal of BST.\n";
    cout<<"4.Print In-Order Traversal of BST.\n";
    cout<<"5.Print Post-Order Traversal of BST.\n";
    cout<<"6.Find Maximum Key in BST.\n";
    cout<<"7.Find Minimum Key in BST.\n";
    cout<<"8.Find Value of a Node with a Particular Key in BST.\n";
    cout<<"9.Find Successor of a node in BST.\n";
    cout<<"10.Find Predecessor of a node in BST.\n";
    cout<<"11.Find Height of BST.\n";
    cout<<"12.Find Size of BST.\n";
    cout<<"13.Print BST.\n";
    cout<<"14.Exit.\n";
    cout<<"BST << ";
    cin>>c;
    switch(c)
    {
    

        case 1: 
                cout<<"Enter Key:";
                cin>>key;
                cout<<"Enter Value:";
                cin>>value;
                if(a.get(key))
                cout<<"Key Already Exists"<<endl;
                else a.put(key,value);
                break;
        case 2: 
                cout<<"Enter Key:";
                cin>>key;
                if(a.get(key))
                a.remove(key);
                else 
                cout<<"Key Not Found"<<endl;
                break;
        case 3: 
                a.print_pre_order();
                cout<<endl;
                break;                
        case 4: 
                a.print_in_order();
                cout<<endl;
                break;
        case 5: 
                a.print_post_order();
                cout<<endl;
                break;
        case 6:
                cout<<a.maximum()<<endl;
                break;
        case 7:
                cout<<a.minimum()<<endl;
                break;

        case 8:
                cout<<"Enter Key:";
                cin>>key;
                if(a.get(key))
                cout<<a.get(key)<<endl;
                else 
                cout<<"Key Not Found"<<endl;
                break;
        case 9:
                cout<<"Enter Key:";
                cin>>key;
                if(a.get(key))
                {
                if(a.successor(key))
                cout<<a.successor(key)<<endl;
                else 
                cout<<"Successor Not Found"<<endl;
                }        

                else 
                cout<<"Key Not Found"<<endl;
                break;
        case 10:
                cout<<"Enter Key:";
                cin>>key;
                if(a.get(key))
                {
                if(a.predecessor(key))                    
                cout<<a.predecessor(key)<<endl;
                else 
                cout<<"Predecessor Not Found"<<endl;
                }
                else 
                cout<<"Key Not Found"<<endl;
                break; 
        case 11:
                cout<<"Height of BST is "<<a.getHeight()<<endl;
                break;
        case 12:
                cout<<"Size of BST is "<<a.size()<<endl;
                break;
        case 13:
                a.print();
                break;
        case 14:
                return 0;
        default:
                cout<<"Invalid Choice"<<endl;
                break;                
    }
    }
    return 0;
}