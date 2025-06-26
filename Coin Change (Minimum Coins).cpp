#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>&v,int t, int n,vector<vector<int>>&dp)
{
    if(t==0) return 0;
    if(n==0) return 1e9;

    if(dp[n][t]!=-1) return dp[n][t];

    if(t>=v[n-1])
        dp[n][t]=min(1+ans(v,t-v[n-1],n,dp),ans(v,t,n-1,dp));
    else
        dp[n][t] = ans(v,t,n-1,dp);
    return dp[n][t];
}
int minCoins(vector<int> &v, int sum)
{
    int n = v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    int res =  ans(v,sum,n,dp);
    if(res==1e9) return -1;
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target=0;
    cin>>target;
    cout<<minCoins(v,target)<<endl;
    return 0;
}
/**

4
9 6 5 1
19

*/
