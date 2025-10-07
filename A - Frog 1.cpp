#include<bits/stdc++.h>
using namespace std;

int ans(int i, vector<int>&v, vector<int>&dp)
{
    if(i==v.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    if(i+2<v.size())
        return dp[i] = min((ans(i+1,v,dp)+abs(v[i]-v[i+1])),(ans(i+2,v,dp)+abs(v[i]-v[i+2])));
    else
        return dp[i] = ans(i+1,v,dp)+abs(v[i]-v[i+1]);
}
int findAns(vector<int>&v)
{
    int n = v.size();
    vector<int>dp(n,-1);
    return ans(0,v,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<findAns(v)<<endl;
    return 0;
}
