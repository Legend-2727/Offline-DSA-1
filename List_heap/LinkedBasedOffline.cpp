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

template <class T>
class MyLinkedList
{
    Data<T> *head, *cur,*tail;
    int len,pos;

    public:
        MyLinkedList()
        {
            head = NULL;
            tail = NULL;
            cur= NULL;
            len = 0;
            pos=0;
        }
        int size()
        {
            return len;
        }
        void push(T item)
        {
            Data<T> *temp;
            temp = new Data<T>(item);
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                cur = head;
            }
            else if(pos==0)
            {
                temp->next=head;
                head=temp;
                cur=temp;
            }
            else
            {
                Data<T> *temp2;
                temp2=head;
                int i=0;
                while(temp2!=NULL && i<pos)
                {
                    temp2=temp2->next;
                    i++;
                }
                temp->next=temp2->next;
                temp2->next=temp;
                cur=temp;
                if(cur==NULL)
                {
                    tail=temp2;
                }
            }
            len++;
        }
        void pushBack(T item)
        {
            Data<T> *temp;
            temp=new Data<T>(item);
            if(head==NULL)
            {
                tail=temp;
                head=temp;
                cur=temp;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
            len++;
        }
        T erase()
        {
            // Data<T> *temp;
            // temp=head;
            //while(cur!=temp) temp=temp->next;
            T x=cur->value;
            if(cur==head)
            {
                x=head->value;
                head=head->next;
                cur=head;
            }
            else{
                Data<T> *temp;
                temp=head;
                while(temp->next!=cur)
                {
                    temp=temp->next;
                }
                temp->next=cur->next;
                if(temp->next!=NULL) cur=temp->next;
                else 
                {
                    cur=temp;
                    pos--;
                }
            }
            len--;
            return x;
        }
        void setToBegin()
        {
            cur=head;
            pos=0;
        }
        void setToEnd()
        {
            while(cur->next!=NULL)
            {
               cur=cur->next;
            }
            pos=len-1;
        }
        void setToPos(int x)
        {
            cur=head;
            int i=0;
            while(i<x)
            {
                cur=cur->next;
                i++;
            }
            pos=x;
        }
        void prev()
        {
            if(pos==0) return;
            Data<int> *temp;
            temp=head;
            while(temp->next !=cur)
            {
                temp=temp->next;
            }
            cur=temp;
            pos--;
        }
        int currPos()
        {
            return pos;
        }
        void next()
        {
            if(pos==len-1) return;
            cur=cur->next;
            pos++;
        }
        T getValue()
        {
            return cur->value;
        }
        int find(T item)
        {
            Data<T> *temp;
            temp=head;
            int i=0;
            
            while(temp!=NULL && temp->value!=item)
            {
                temp=temp->next;
                i++;
            }
            if(temp==NULL)
            {
                return -1;
            } 
            return i;
        }
        void clear()
        {
            Data<T> *temp;
            temp=head;
            while(temp!=NULL)
            {
                head=head->next;
                delete temp;
                temp=head;
            }
            len=0;
            pos=0;
        }
        void print(ofstream &out,int x)
        {
            out<<"< ";
            Data<T> *temp=head;
            while(temp!=NULL)
            {
                if(temp==cur) out<<"| ";
                out<<temp->value<<" ";
                //out<<temp->value<<"\n";
                temp=temp->next;
            }
            out<<">\n";
            if(x!=-2) out<<x<<"\n";
        }
        ~MyLinkedList()
        {
            clear();
        }
};