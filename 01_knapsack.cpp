#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&val,vector<int>&wt,int n,int w,vector<vector<int>>&dp)
{
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w] = max(help(val,wt,n-1,w-wt[n-1],dp)+val[n-1],help(val,wt,n-1,w,dp));
    }
    else
        return dp[n][w] = help(val,wt,n-1,w,dp);
}
int knapsack(vector<int>val,vector<int>wt,int w)
{
    int n = val.size();
//    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
//    int ans1 = help(val,wt,n,w,dp);
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j)
                dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}/**
4
1 4 5 7
1 3 4 5
7
*/int main()
{
    int n;
    cin>>n;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    int w;
    cin>>w;
    cout<<knapsack(val,wt,w)<<endl;
    return 0;
}
