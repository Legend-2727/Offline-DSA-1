#include "BST.cpp"
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    BST<int> bst;

    while(!fin.eof())
    {
        string s,p;
        fin>>s>>p;
        if(s=="I")
        {
            bst.Insert(stoi(p));
            bst.print(fout,bst.getRoot());
        }
        else if(s=="D")
        {
            int x=bst.Delete(fout,stoi(p));
            if(x==1) bst.print(fout,bst.getRoot());
        }
        else if(s=="F")
        {
            if(bst.Find(stoi(p)))
                fout<<"True";
            else fout<<"False";
        }
        else if(s=="T")
        {
            if(p=="In")
            {
                bst.inOrderTraverse(fout,bst.getRoot());
            }
            else if(p=="Pre")
            {
                bst.preOrderTraverse(fout,bst.getRoot());
            }
            else if(p=="Post")
            {
                bst.postOrderTravers(fout,bst.getRoot());
            }
        }
        fout<<"\n";
    }
    return 0;
}