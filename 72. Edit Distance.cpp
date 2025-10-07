#include<bits/stdc++.h>
using namespace std;

int help(int n, int m ,string &s, string &t, vector<vector<int>>&dp)
{
    if(m==0) return n;
    if(n==0) return m;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==t[m-1])
        return dp[n][m] = help(n-1,m-1,s,t,dp);
    else
        return dp[n][m]=min({help(n-1,m,s,t,dp),help(n,m-1,s,t,dp),help(n-1,m-1,s,t,dp)})+1;
}
int minDistance(string s, string t)
{
   int n = s.size(), m = t.size();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   return help(n,m,s,t,dp);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minDistance(s,t)<<endl;
    return 0;
}
/**

abac
cab

horse
ros


*/
