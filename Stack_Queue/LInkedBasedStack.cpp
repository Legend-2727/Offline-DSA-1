#include<bits/stdc++.h>
using namespace std;

template <class T>
class Data
{
public:
    T value;
    Data<T> *next;
    Data(T item)
    {
        value = item;
        next = NULL;
    }
};

template<class T>
class MyLinkedStack{
    Data<T> *head;
    int currLen;
public:
    MyLinkedStack()
    {
        currLen=0;
        head=NULL;
    }
    void push(T item)
    {
        Data<T> *temp;
        temp=new Data<T>(item);
        temp->next=head;
        head=temp;
        currLen++;
    }
    T pop()
    {
        if(head==NULL) return -1;
        Data<T> *temp;
        temp=head;
        head=head->next;
        currLen--;
        return temp->value;
    }
    int length()
    {
        return currLen;
    }
    T topValue()
    {
        if(head==NULL) return -1;
        return head->value;
    }
    void clear()
    {
        Data<T> *temp;
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            delete head;
        }
        head=NULL;
        currLen=0;
    }
    void print(ofstream &out,int x)
    {
        T tempArr[currLen];
        out<<"< ";
         Data<T> *temp=head;
         int i=0;
        while(temp!=NULL)
        {
            tempArr[i]=temp->value;
            temp=temp->next;
            i++;
        }
        for(int i=0;i<currLen;i++)
        {
            if(i==currLen-1) out<<"| ";
            out<<tempArr[currLen-1-i]<<" ";
        }
        out<<">\n";
        if(x!=-2) out<<x<<"\n";
    }
};