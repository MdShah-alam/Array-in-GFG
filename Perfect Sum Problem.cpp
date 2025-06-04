#include<bits/stdc++.h>
using namespace std;

int ans(int n, vector<int>&v, int t, vector<vector<int>>&dp){
        if(n==0){
            if(t==0) return 1;
            return 0;
        }
        if(dp[n][t]!=-1) return dp[n][t];
        if(v[n-1]<=t)
            dp[n][t] = ans(n-1,v,t-v[n-1],dp)+ans(n-1,v,t,dp);
        else
            dp[n][t]=ans(n-1,v,t,dp);
        return dp[n][t];
    }
int perfectSum(vector<int>& arr, int t)
{
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        int a = ans(n,arr,t,dp);
        return a;
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
    cout<<perfectSum(v,t)<<endl;
    return 0;
}

/**

6
5 2 3 10 6 8
10

*/
