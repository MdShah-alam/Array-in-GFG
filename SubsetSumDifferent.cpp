#include<bits/stdc++.h>
using namespace std;

bool help(vector<int>&b, int n, int t, vector<vector<bool>>&dp)
{
    if(t==0) return true;
    if(n==0) return false;
    if(dp[n][t]!=false) return dp[n][t];
    if(t>=b[n-1])
        return dp[n][t] = help(b,n-1,t-b[n-1],dp) || help(b,n-1,t,dp);
    else
        return dp[n][t] = help(b,n-1,t,dp);
}
bool SubsetSumDifferent(vector<int>&b,int diff)
{
    int n = b.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=b[i];
    sum-=diff;
    if(sum%2!=0) return false;
    int t = sum/2;
    vector<vector<bool>>dp(n+1,vector<bool>(t+1,false));
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
    cout<<SubsetSumDifferent(b,diff)<<endl;
    return 0;
}
/**

4
1 1 2 3
1

*/
