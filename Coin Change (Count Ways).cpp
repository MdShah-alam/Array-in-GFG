#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>&v,int n,int t,vector<vector<int>>&dp)
{
    if(n==0){
        if(t==0) return 1;
        return 0;
    }
    if(dp[n][t]!=-1) return dp[n][t];

    if(t>=v[n-1])
        dp[n][t] = ans(v,n,t-v[n-1],dp) + ans(v,n-1,t,dp);
    else
        dp[n][t] = ans(v,n-1,t,dp);
    return dp[n][t];
}
int count(vector<int>& v, int sum)
{
    int n = v.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1 , -1));
    return ans(v,n,sum,dp);
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
    cout<<count(v,target)<<endl;
    return 0;
}
/**

3
1 2 3
4

4
2 5 3 6
10

2
5 10
3

*/
