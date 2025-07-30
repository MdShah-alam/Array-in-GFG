#include<bits/stdc++.h>
using namespace std;


int help(vector<int>&dp,int n,int x, int y, int z)
{
    if(n==0) return 0;
    if(n<0) return -1;
    if(dp[n]!=-1) return dp[n];

    int p1=help(dp,n-x,x,y,z);
    int p2=help(dp,n-y,x,y,z);
    int p3=help(dp,n-z,x,y,z);

    int maxp=max({p1,p2,p3});
    if(maxp==-1) return dp[n]=maxp;
    return dp[n]=1+maxp;
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int>dp(n+1);
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    int ans = help(dp,n,x,y,z);
    return ans<0 ? 0:ans;
}

int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<maximizeTheCuts(n,x,y,z)<<endl;
    return 0;
}
