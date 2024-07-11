#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyArrayStack{
    T *items;
    int default_size;
    int currLen;
    int maxLen;
    void expandMaxSize()
    {
        T *temp=new T[currLen];
        for(int i=0;i<currLen;i++)
        {
            temp[i]= items[i];
        }
        delete[] items;
        maxLen*=2;
        items=new T[maxLen];
        for(int i=0;i<currLen;i++)
        {
            items[i]=temp[i];
        }
        delete[] temp;
    }
    void shrinkMaxSize()
    {
        T *temp=new T[currLen];
        for(int i=0;i<currLen;i++)
        {
            temp[i]= items[i];
        }
        delete[] items;
        maxLen/=2;
        items=new T[currLen];
        for(int i=0;i<currLen;i++)
        {
            items[i]=temp[i];
        }
        delete[] temp;
    }
public:
    MyArrayStack()
    {
        maxLen=10;
        default_size=10;
        currLen=0;
        items=new T[maxLen];
    }
    MyArrayStack(int size)
    {
        maxLen=size;
        default_size=size;
        currLen=0;
        items=new T[maxLen];
    }
    void clear()
    {
        delete[] items;
        maxLen=default_size;
        currLen=0;
        items=new T[maxLen];
    }
    void push(T item)
    {
        if((currLen+1)>maxLen)
            expandMaxSize();
        items[currLen++]=item;
    }
    T pop()
    {
        if(currLen==0) return -1;
        T temp=items[currLen-1];
        currLen--;
        if((currLen)<(maxLen/2) && (maxLen/2)>default_size)
            shrinkMaxSize();
        return temp;
    }
    int length()
    {
        return currLen;
    }
    T topValue()
    {
        if(currLen==0) return -1;
        return items[currLen-1];
    }
    void print(ofstream &out,int x)
    {
        out<<"< ";
        for(int i=0;i<currLen;i++)
        {
            if(i==currLen-1) out<<"| ";
            out<<items[i]<<" ";
        }
        out<<">\n";
        if(x!=-2) out<<x<<"\n";
    }
};
