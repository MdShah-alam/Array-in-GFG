#include<bits/stdc++.h>
using namespace std;

int countleter(int i, int j, string &s, vector<vector<int>>&dp)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
        dp[i][j] = countleter(i+1,j-1,s,dp);
    else{
        dp[i][j] = min(countleter(i+1,j,s,dp),countleter(i,j-1,s,dp))+1;
    }
    return dp[i][j];
}
int minDelations(string &s)
{
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int k = countleter(0,n-1,s,dp);
    return k;
}
int main()
{
    string s;
    cin>>s;
    cout<<minDelations(s)<<endl;
    return 0;
}
