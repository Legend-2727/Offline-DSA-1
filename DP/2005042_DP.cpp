#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>matrix;
vector<int> items;
vector<pair<int,int>> vp;
int knapsack(int k,int w)
{
    if(matrix[k][w]!=-1) 
        return matrix[k][w];
    if(k<=0 || w<=0) 
        return matrix[k][w]=0;
    if(vp[k].first>w)
        return matrix[k][w]=knapsack(k-1,w);
    return matrix[k][w]=max(vp[k].second+knapsack(k-1,w-vp[k].first),knapsack(k-1,w));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    matrix.resize(n+1);
    vp.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>vp[i].first>>vp[i].second;
    }
    int max_weight;
    cin>>max_weight;
    for(int i=0;i<=n;i++) matrix[i].resize(max_weight+1,-1);
    int ans=knapsack(n,max_weight);
    cout<<ans<<"\n";
    int i=n,j=max_weight;
    while (i>0 && j>0)
    {
        if(matrix[i-1][j]==matrix[i][j])
        {
            i--;
        }
        else{
            items.push_back(vp[i].first);
            j-=vp[i--].first;
        }
    }
    //sort(items.begin(),items.end());
    for(auto it:items)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}