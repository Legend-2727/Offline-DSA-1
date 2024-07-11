#include "ArrayBasedStack.cpp"
#include "LinkedBasedStack.cpp"
#include "ArrayBasedQueue.cpp"
#include "LinkedBasedQueue.cpp"
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int k,x;
    input>>k>>x;
    //MyArrayQueue<int> myQueue(x);
    MyLinkedQueue<int> myQueue;
    for(int i=0;i<k;i++)
    {
        int a;
        input>>a;
        myQueue.enqueue(a);
    }
    int m,y;
    input>>m>>y;
    //MyArrayStack<int> myStack(y);
    MyLinkedStack<int> myStack;
    while(m--)
    {
        int a;
        input>>a;
        myStack.push(a);
    }
    myQueue.print(output,-2);
    myStack.print(output,-2);
    int q;
    input>>q;
    while(q--)
    {
        int f,p;
        input>>f>>p;
        if(f==1)
        {
            myQueue.clear();
            myQueue.print(output,-1);
        }
        else if(f==2)
        {
            myQueue.enqueue(p);
            myQueue.print(output,-1);
        }
        else if(f==3)
        {
            myQueue.print(output,myQueue.dequeue());
        }
        else if(f==4)
        {
            myQueue.print(output,myQueue.length());
        }
        else if(f==5)
        {
            myQueue.print(output,myQueue.frontValue());
        }
        else if(f==6)
        {
            myQueue.print(output,myQueue.rearValue());
        }
        else if(f==7)
        {
            myQueue.print(output,myQueue.leaveQueue());
        }
        if(f==8)
        {
            myStack.clear();
            myStack.print(output,-1);
        }
        else if(f==9)
        {
            myStack.push(p);
            myStack.print(output,-1);
        }
        else if(f==10)
        {
            myStack.print(output,myStack.pop());
        }
        else if(f==11)
        {
            myStack.print(output,myStack.length());
        }
        else if(f==12)
        {
            myStack.print(output,myStack.topValue());
        }
    }
    input.close();
    output.close();
    return 0;
}