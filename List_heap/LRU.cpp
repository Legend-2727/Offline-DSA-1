#include<bits/stdc++.h>
#include "LinkedBasedOffline.cpp"
using namespace std;


template<class T,class V>
class LRU{
    MyLinkedList<T> keys;
    MyLinkedList<V> values;
    int max_capacity;
    int count;
public:
    LRU(int x)
    {
        max_capacity=x;
        count=0;
    }
    void put(T k,V v)
    {
        int x=keys.find(k);
        if(x==-1)
        {
            keys.pushBack(k);
            values.pushBack(v);
            count++;
        }
        else{
            values.setToPos(x);
            keys.setToPos(x);
            T tempK=keys.erase();
            V tempV=values.erase();
            tempV=v;
            keys.pushBack(tempK);
            values.pushBack(tempV);
        }
        if(count>max_capacity)
        {
            values.setToBegin();
            keys.setToBegin();
            values.erase();
            keys.erase();
            count--;
        }
    }
    V get(T k)
    {
        int x=keys.find(k);
        if(x==-1) return -1;
        values.setToPos(x);
        keys.setToPos(x);
        T tempK=keys.erase();
        V tempV=values.erase();
        keys.pushBack(tempK);
        values.pushBack(tempV);
        return tempV;
    }
};

int main() {
    ifstream input("lru_input.txt");
    ofstream output("lru_output.txt");
    int c;
    input>>c;
    LRU<int,int> lru(c);
    int q;
    input>>q;
    while(q--)
    {
        int opt;
        input>>opt;
        if(opt==1)
        {
            int key;
            input>>key;
            output<<lru.get(key)<<"\n";
        }
        else if(opt==2)
        {
            int key,value;
            input>>key>>value;
            lru.put(key,value);
        }
    }
    input.close();
    output.close();
    return 0;
}
