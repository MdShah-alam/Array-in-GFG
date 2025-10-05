#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&v, int n, int t, vector<vector<int>>&dp)
{
    if(t==0) return 1;
    if(n==0) return 0;
    if(dp[n][t]!=-1) return dp[n][t];
    if(t>=v[n-1])
        return dp[n][t] = help(v,n-1,t-v[n-1],dp)+help(v,n-1,t,dp);
    else
        return dp[n][t] = help(v,n-1,t,dp);
}
int CountSum(vector<int>&v,int t)
{
    int n = v.size();
//    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
//    return help(v,n,t,dp);
    int arr[n+1][t+1];
    for(int i=0;i<=t;i++)
        arr[0][i]=0;
    for(int i=0;i<=n;i++)
        arr[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(j>=v[i-1])
                arr[i][j] = arr[i-1][j-v[i-1]]+arr[i-1][j];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][t];
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
    cout<<CountSum(v,t)<<endl;
    return 0;
}
/**

6
2 3 5 6 8 10
10

*/
