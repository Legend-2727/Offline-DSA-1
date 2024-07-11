#include "ArrayBasedOffline1.cpp"
#include "LinkedBasedOffline.cpp"
int main()
{
    ifstream input("list_input.txt");
    ofstream output("list_output.txt");
    int k,x;
    input>>k>>x;
    //MyArrayList<int> myList(x);
    MyLinkedList<int> myList;
    for(int i=0;i<k;i++)
    {
        int a;
        input>>a;
        myList.pushBack(a);
    }
    myList.print(output,-2);
    int q;
    input>>q;
    while(q--)
    {
        int f,p;
        input>>f>>p;
        if(f==1)
        {
            myList.print(output,myList.size());
        }
        else if(f==2)
        {
            myList.push(p);
            myList.print(output,-1);
        }
        else if(f==3)
        {
            myList.pushBack(p);
            myList.print(output,-1);
        }
        else if(f==4)
        {
            myList.print(output,myList.erase());
        }
        else if(f==5)
        {
            myList.setToBegin();
            myList.print(output,-1);
        }
        else if(f==6)
        {
            myList.setToEnd();
            myList.print(output,-1);;
        }
        else if(f==7)
        {
            myList.prev();
            myList.print(output,-1);
        }
        else if(f==8)
        {
            myList.next();
            myList.print(output,-1);
        }
        else if(f==9)
        {
            myList.print(output,myList.currPos());
        }
        else if(f==10)
        {
            myList.setToPos(p);
            myList.print(output,-1);
        }
        else if(f==11)
        {
            myList.print(output,myList.getValue());
        }
        else if(f==12)
        {
            myList.print(output,myList.find(p));
        }
        else if(f==13)
        {
            myList.clear();
            myList.print(output,-2);
        }
    }
    input.close();
    output.close();
    return 0;
}