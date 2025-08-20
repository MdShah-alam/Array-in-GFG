#include<bits/stdc++.h>
using namespace std;

int help(int n, int t, vector<int>v, vector<vector<int>>&dp)
{
    if(n==0){
        if(t==0) return 1;
        return 0;
    }
    if(dp[n][t]!=-1) return dp[n][t];
    if(t>=v[n-1])
        return dp[n][t]=help(n,t-v[n-1],v,dp);
    else
        return dp[n][t]=help(n-1,t,v,dp);
}
int coinChange(vector<int>v,int t)
{
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    return help(n,t,v,dp);
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
    cout<<coinChange(v,t)<<endl;
    return 0;
}
