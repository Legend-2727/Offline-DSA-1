#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vp;

void merge_count(int arr[],int l,int r,int m)
{
    int ln,rn;
    ln=m-l,rn=r-m;
    vector<int> left(ln),right(rn);
    for(int i=l;i<m;i++)
        left[i-l]=arr[i];
    for(int i=m;i<r;i++)
        right[i-m]=arr[i];
    int k=l;
    int i=0,j=0;
    while(i<ln && j<rn)
    {
        if(left[i]<=right[j])
        {
            arr[k++]=left[i++];
        }
        else{
            for(int x=i;x<ln;x++)
                vp.push_back(make_pair(left[x],right[j]));
            arr[k++]=right[j++];
        }
    }
    while(i<ln) arr[k++]=left[i++];
    while(j<rn) arr[k++]=right[j++];
}

void sort_count(int arr[],int begin,int end)
{
    
    if(begin<(end-1)){
        int middle=(begin+end)/2;
        sort_count(arr,begin,middle);
        sort_count(arr,middle,end);

        merge_count(arr,begin,end,middle);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort_count(arr,0,n);
    cout<<vp.size()<<"\n";
    sort(vp.begin(),vp.end());
    if(vp.size()!=0) cout<<"The inverted pairs are: ";
    for(int i=0;i<vp.size();i++)
    {
        cout<<"("<<vp[i].first<<","<<vp[i].second<<")";
        if(i!=vp.size()-1) cout<<",";
    }
    cout<<"\n";
    return 0;
}