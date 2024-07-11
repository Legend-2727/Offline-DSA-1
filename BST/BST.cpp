#include<bits/stdc++.h>
using namespace std;

template<class T>
class BSTnode{
public:
    T value;
    BSTnode *left_child;
    BSTnode *right_child;
    BSTnode(T v)
    {
        value=v;
        left_child=NULL;
        right_child=NULL;
    }
};

template<class T>
class BST
{
    BSTnode<T> *root;
public:
    BST()
    {
        root=NULL;
    }
    void Insert(T item) {
        if (root == NULL)
            root = new BSTnode<T>(item);
        else
            root = assign(root,item);
    }
    BSTnode<T>* assign(BSTnode<T> *loc,T item)
    {
        if(loc==NULL){
            return new BSTnode<T>(item);
        }
        if (item > loc->value) {
            loc->right_child = assign(loc->right_child, item);
        }
        else if (item < loc->value){
            loc->left_child = assign(loc->left_child, item);
        }
        return loc;
    }
    int Delete(ofstream &out,T item)
    {
        BSTnode<T> *temp=root;
        while(true)
        {
            if(temp==NULL)
            {
                out<<"No Item\n";
                return 0;
            }
            if(isLeaf(temp))
            {
                root=NULL;
                return 0;
            } 
            if(item<temp->value)
            {
                BSTnode<T> *temp2=temp->left_child;
                if(isLeaf(temp2))
                {
                    if(temp2->value!=item)
                    {
                        out<<"INVALID ITEM FOR DELETION\n";
                        return 0;
                    } 
                    else{
                        temp->left_child=NULL;
                        delete temp2;
                        return 1;
                    }
                    break;
                }
                else{
                    temp=temp2;
                }
            }
            else if(item>temp->value)
            {
                BSTnode<T> *temp2=temp->right_child;
                if(isLeaf(temp2))
                {
                    if(temp2->value!=item)
                    {
                        out<<"INVALID ITEM FOR DELETION\n";
                        return 0;
                    } 
                    else{
                        temp->right_child=NULL;
                        delete temp2;
                        return 1;
                    }
                    break;
                }
                else{
                    temp=temp2;
                }
            }
            else{
                out<<"Invalid Operation\n";
                return 0;
            }
        }
    }
    bool Find(T item)
    {
        BSTnode<T> *temp=root;
        while(temp!=NULL)
        {
            if(temp->value==item) return true;
            if(item<temp->value) temp=temp->left_child;
            else temp=temp->right_child;
        }
        return false;
    }
    bool isLeaf(BSTnode<T> *b)
    {
        return b->left_child==NULL && b->right_child==NULL;
    }
    void inOrderTraverse(ofstream &out,BSTnode<T> *init)
    {
        if (init == nullptr) return;
        inOrderTraverse(out,init->left_child);
        out << init->value << " ";
        inOrderTraverse(out,init->right_child);
    }
    void preOrderTraverse(ofstream &out,BSTnode<T> *init)
    {
        if (init == nullptr) return;
        out << init->value << " ";
        preOrderTraverse(out,init->left_child);
        preOrderTraverse(out,init->right_child);
    }
    void postOrderTravers(ofstream &out,BSTnode<T> *init)
    {   
        if(init==NULL) return;
        postOrderTravers(out,init->left_child);
        postOrderTravers(out,init->right_child);
        out<<init->value<<" ";
    }
    void print(ofstream &out,BSTnode<T> *init)
    {
        if (init == nullptr) return;
        out << init->value;
        if(!isLeaf(init))
        {
            out<<"(";
            print(out,init->left_child);
            out<<")(";
            print(out,init->right_child);
            out<<")";   
        }
    }
    BSTnode<T> *getRoot(){
        return root;
    }
};