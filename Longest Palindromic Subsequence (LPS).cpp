#include<bits/stdc++.h>
using namespace std;

int findlength(int i, int j,string &s , vector<vector<int>>&dp)
{
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
        dp[i][j]=findlength(i+1,j-1,s,dp)+2;
    else
        dp[i][j]=max(findlength(i+1,j,s,dp),findlength(i,j-1,s,dp));
    return dp[i][j];
}
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans = findlength(0,n-1,s,dp);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s)<<endl;
    return 0;
}
