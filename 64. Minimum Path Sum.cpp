#include<bits/stdc++.h>
using namespace std;

int help(int n,int m,vector<vector<int>>v,vector<vector<int>>&dp)
{
    if(n==0&&m==0) return v[0][0];
    if(dp[n][m]!=-1) return dp[n][m];
    int val1=1e9,val2=1e9;
    if(n>0)
        val1=help(n-1,m,v,dp);
    if(m>0)
        val2=help(n,m-1,v,dp);
    return dp[n][m]=min(val1,val2)+v[n][m];
}
int minPathSum(vector<vector<int>>&v)
{
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return help(n-1,m-1,v,dp);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }

    cout<<minPathSum(v)<<endl;
    return 0;
}
/**

3 3
1 3 1
1 5 1
4 2 1

*/
