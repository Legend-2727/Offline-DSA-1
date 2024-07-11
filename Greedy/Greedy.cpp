#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> pv;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        pv.push_back(make_pair(b,a));
    }
    sort(pv.begin(),pv.end());
    int last_finish=pv[0].first;
    vector<pair<int,int>> result_pair;
    result_pair.push_back(make_pair(pv[0].second,pv[0].first));
    for(int i=1;i<n;i++)
    {
        if(pv[i].second>=last_finish){
            last_finish=pv[i].first;
            result_pair.push_back(make_pair(pv[i].second,pv[i].first));
        }
    }
    cout<<result_pair.size()<<"\n";
    for(auto it:result_pair){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;
}