#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&val,vector<int>&wt,int n,int cap, vector<vector<int>>&dp)
{
    if(cap==0 || n==0) return 0;
    if(dp[n][cap]!=-1) return dp[n][cap];
    if(wt[n-1]<=cap){
        return dp[n][cap]=max(help(val,wt,n,cap-wt[n-1],dp)+val[n-1],help(val,wt,n-1,cap,dp));
    }
    else
        return dp[n][cap]=help(val,wt,n-1,cap,dp);
}
int knapSack(vector<int>& val, vector<int>& wt, int capacity)
{
    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
    int ans = help(val,wt,n,capacity,dp);
    if(ans==-1) return 0;
    else return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    int cap;
    cin>>cap;
    cout<<knapSack(val,wt,cap)<<endl;
    return 0;
}
/**

4
6 1 7 7
1 3 4 5
8

*/
