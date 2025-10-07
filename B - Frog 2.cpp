#include<bits/stdc++.h>
using namespace std;

int ans(int i, int k, vector<int>&v, vector<int>&dp)
{
    if(i==v.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int res=1e9;
    for(int j=i+1;j<=i+k;j++){
        if(j>=v.size()) break;
        res = min(res,ans(j,k,v,dp)+abs(v[i]-v[j]));
    }
    return dp[i] = res;
}
int findAns(vector<int>&v, int k)
{
    int n = v.size();
    vector<int>dp(n,-1);
    return ans(0,k,v,dp);
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<findAns(v,k)<<endl;
    return 0;
}

