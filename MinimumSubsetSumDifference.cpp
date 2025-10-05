#include<bits/stdc++.h>
using namespace std;

bool help(vector<int>&v, vector<vector<bool>>&dp, int n, int t)
{
    if(t==0) return true;
    if(n==0) return false;
    if(dp[n][t]!=false) return dp[n][t];
    if(t>=v[n-1])
        return dp[n][t] = help(v,dp,n-1,t-v[n-1]) || help(v,dp,n-1,t);
    else
        return dp[n][t] = help(v,dp,n-1,t);
}
int MinimumSubsetSumDifferent(vector<int>&v)
{
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=v[i];
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    bool found = help(v,dp,n,sum);
    cout<<found<<endl;
    for(int i=0;i<=sum;i++)
        cout<<dp[n][i]<<" ";
    cout<<endl;
    return 2;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<MinimumSubsetSumDifferent(v)<<endl;
    return 0;
}
