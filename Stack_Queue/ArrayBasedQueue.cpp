#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyArrayQueue{
    T *items;
    int front,rear;
    int default_size;
    int currSize;
    int max_size;
    void expandQueue()
    {
        T temp[currSize];
        for(int i=0;i<currSize;i++)
        {
            temp[i]=items[front+i];
        }
        delete [] items;
        max_size*=2;
        items=new T[max_size];
        for(int i=0;i<currSize;i++)
        {
            items[i]=temp[i];
        }
        front=0,rear=currSize-1;
    }
    void shrinkQueue()
    {
        T temp[currSize];
        for(int i=0;i<currSize;i++)
        {
            temp[i]=items[front+i];
        }
        delete [] items;
        max_size/=2;
        if(max_size<default_size) max_size=default_size;
        items=new T[max_size];
        for(int i=0;i<currSize;i++)
        {
            items[i]=temp[i];
        }
        front=0;
        rear=currSize-1;
    }
public:
    MyArrayQueue(int x=10)
    {
        default_size=max_size=x;
        items=new T[max_size];
        front=0;
        rear=-1;
        currSize=0;
    }
    void clear()
    {
        delete [] items;
        items=new T[default_size];
        front=0;
        rear=-1;
        currSize=0;
    }
    void enqueue(T item)
    {
        if(rear==-1){
            items[front]=item;
            rear++;
        }
        else{
            if((rear+2)%max_size==front) expandQueue();
            rear=(rear+1)%max_size;
            items[rear]=item;
        }
        currSize++;
    }
    T dequeue()
    {
        if(currSize==0) return -1;
        T temp=items[front];
        if((currSize+1)<(max_size/2) && (max_size/2)>default_size)
        {
            shrinkQueue();
        } 
        front=(front+1)%max_size;
        currSize--;
        return temp;
    }
    int length(){
        return currSize;
    }
    T frontValue()
    {
        return items[front];
    }
    T rearValue(){
        return items[rear];
    }
    T leaveQueue()
    {
        if(currSize==0) return -1;
        if((currSize+1)<(max_size/2) && (max_size/2)>default_size)
        {
            shrinkQueue();
        }
        T temp=items[rear];
        rear=(front+currSize-2)%max_size;
        currSize--;
        return temp;
    }
    void print(ofstream &out,int x)
    {

        out<<"< ";
        if(currSize!=0) out<<"| ";
        int i=0;
        while(i<currSize)
        {
            out<<items[(i+front)%max_size]<<" ";
            i++;
        }
        out<<">\n";
        if(x!=-2) out<<x<<endl;
        //out<<"eita "<<max_size<<" "<<currSize<<" "<<front<<" "<<rear<<endl;
    }
};