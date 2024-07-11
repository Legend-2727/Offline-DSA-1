#include<bits/stdc++.h>
using namespace std;

template <class T>
class ListData
{
public:
    T value;
    ListData<T> *next;
    ListData(T item)
    {
        value = item;
        next = NULL;
    }
};

template<class T>
class MyLinkedQueue{
    ListData<T> *head,*tail;
    int currLen;
public:
    MyLinkedQueue()
    {
        currLen=0;
        head=NULL;
        tail=NULL;
    }
    void clear()
    {
        ListData<T> *temp;
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            delete head;
        }
        head=NULL;
        tail=NULL;
        currLen=0;
    }
    void enqueue(T item)
    {
        ListData<T> *temp;
        temp=new ListData<T>(item);
        if(head==NULL)
        {
            head=temp;
            head->next=tail;
        }
        else{
            if(tail==NULL)
            {
                head->next=tail=temp;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
        }
        currLen++;
    }
    T dequeue()
    {
        if(currLen==0)
        {
            return -1;
        }
        ListData<T> *temp;
        temp=head;
        T tempValue=head->value;
        head=head->next;
        currLen--;
        if(currLen==1) tail==NULL;
        if(currLen==0)
        {
            head=NULL;
            tail=NULL;
        }
        delete temp;
        return tempValue;
    }
    T frontValue()
    {
        return head->value;
    }
    T rearValue()
    {
        if(tail== NULL) return head->value;
        return tail->value;
    }
    int length()
    {
        return currLen;
    }
    T leaveQueue()
    {
        if(currLen==0) return -1;
        ListData<T> *temp;
        temp=head;
        T tempValue;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        if(tail!=NULL)
        {
            tempValue=tail->value;
            tail=temp;
            temp->next=NULL;
        } 
        else 
        {
            tempValue=temp->value;
        }
        currLen--;
        if(currLen==1) tail=NULL;
        if(currLen==0)
        {
            head=NULL;
            tail=NULL;
        }
        return tempValue;
    }
    void print(ofstream &out,int x)
    {
        out<<"< ";
        ListData<T> *temp=head;
        while(temp!=NULL)
        {
            if(temp==head) out<<"| ";
            out<<temp->value<<" ";
            temp=temp->next;
        }
        out<<">\n";
        if(x!=-2) out<<x<<"\n";
    }
};