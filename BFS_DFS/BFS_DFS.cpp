#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt"); 
vector<int> visited;
vector<vector<int>> adj;
vector<pair<int,int>> vp;
void BFS(int x)
{
    queue<int> q;
    q.push(x);
    visited[x]=true;
    vp.clear();
    while(!q.empty())
    {
        int temp=q.front();
        fout<<temp<<" ";
        q.pop();

        for(int i=0;i<adj[temp].size();i++)
        {
            if(!visited[adj[temp][i]])
            {
                
                visited[adj[temp][i]]=1;
                vp.push_back(make_pair(temp,adj[temp][i]));
                q.push(adj[temp][i]);
            }
        }
    }
    
    fout<<"\n";
    for(int i=0;i<vp.size();i++)
    {
        fout<<vp[i].first<<"->"<<vp[i].second<<endl;
    }
    for(int i=0;i<visited.size();i++)
    {
        visited[i+1]=0;
    }
    vp.clear();
}

void DFS(int x)
{
    fout<<x<<" ";
    visited[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            vp.push_back(make_pair(x,adj[x][i]));
            DFS(adj[x][i]);
        }
    }
}
void print()
{
    fout<<"\n";
    for(int i=0;i<vp.size();i++)
        fout<<vp[i].first<<"->"<<vp[i].second<<endl;
    vp.clear();
}

int main()
{

    int n,m;
    fin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        fin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int root;
    fin>>root;
    fout<<"BFS tree\n";
    BFS(root);
    fout<<"DFS tree\n";
    DFS(root);
    print();
    return 0;
}