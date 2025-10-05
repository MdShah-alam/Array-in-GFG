#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&v, int n, int t, vector<vector<int>>&dp)
{
    if(t==0) return 1;
    if(n==0) return 0;
    if(dp[n][t]!=-1) return dp[n][t];
    if(t>=v[n-1])
        return dp[n][t]=help(v,n,t-v[n-1],dp)+help(v,n-1,t,dp);
    else
        return dp[n][t]=help(v,n-1,t,dp);
}
int change(int t, vector<int>& v)
{
    if(t==0) return 0;
    int n = v.size();
    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    return help(v,n,t,dp);
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
    cout<<change(t,v)<<endl;
    return 0;
}
/**

3
1 2 5
11


3
1 2 5
5

*/

