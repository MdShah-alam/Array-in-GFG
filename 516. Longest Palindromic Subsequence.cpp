#include<bits/stdc++.h>
using namespace std;

int help(int i, int j, string s, vector<vector<int>>&dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j] = help(i+1,j-1,s,dp)+2;
    else return dp[i][j] = max(help(i+1,j,s,dp),help(i,j-1,s,dp));
}
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return help(0,n-1,s,dp);
}
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s)<<endl;
    return 0;
}
