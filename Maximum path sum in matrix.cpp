#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int fun(int r, int c, vector<vector<int>>&v)
{
    if(c<0 || c>=v[0].size()) return 0;
    if(r==v.size()) return 0;

    if(dp[r][c]!=-1) return dp[r][c];

    int down = fun(r+1,c,v);
    int downLeft = fun(r+1,c-1,v);
    int downRight = fun(r+1,c+1,v);

    return dp[r][c] = max({down, downLeft,downRight})+v[r][c];
}
int maximumPath(vector<vector<int>>&v)
{
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<v[0].size();i++){
        ans = max(ans, fun(0,i,v));
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }

    cout<<maximumPath(v)<<endl;
    return 0;
}
