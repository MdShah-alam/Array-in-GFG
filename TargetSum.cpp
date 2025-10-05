#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&b, int n, int t, vector<vector<int>>&dp)
{
    if(t==0) return 1;
    if(n==0) return 0;
    if(dp[n][t]!=-1) return dp[n][t];
    if(t>=b[n-1])
        return dp[n][t] = help(b,n-1,t-b[n-1],dp) + help(b,n-1,t,dp);
    else
        return dp[n][t] = help(b,n-1,t,dp);
}
int TargetSum(vector<int>&b,int diff)
{
    int n = b.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=b[i];
    sum-=diff;
    if(sum%2!=0) return 0;
    int t = sum/2;
    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    return help(b,n,t,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    int diff;
    cin>>diff;
    cout<<TargetSum(b,diff)<<endl;
    return 0;
}
/**

4
1 1 2 3
1

*/
