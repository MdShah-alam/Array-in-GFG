#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&v,int n,int t)
{
    if(n==-1){
        if(t==0)
            return 1;
        return 0;
    }
    return fun(v,n-1,t-v[n])+fun(v,n-1,t);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int t;
    cin>>t;
    cout<<fun(v,n-1,t)<<endl;
    return 0;
}
