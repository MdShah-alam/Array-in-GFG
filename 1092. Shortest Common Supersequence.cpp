#include<bits/stdc++.h>
using namespace std;

int help(int n, int m ,string &s, string &t, vector<vector<int>>&dp)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    if(s[n-1]==t[m-1])
        return dp[n][m]=1+help(n-1,m-1,s,t,dp);
    else
        return dp[n][m]=max(help(n-1,m,s,t,dp),help(n,m-1,s,t,dp));
}
string shortestCommonSupersequence(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    int ans = help(n,m,s,t,dp);

    string st="";
    while(n && m){
        if(s[n-1]==t[m-1]){
            st+=s[n-1];
            n--;
            m--;
        }
        else if(dp[n-1][m]>dp[n][m-1]){
            st+=s[n-1];
            n--;
        }
        else{
            st+=t[m-1];
            m--;
        }
    }
    while(n){
        st+=s[n-1];
        n--;
    }
    while(m){
        st+=t[m-1];
        m--;
    }
    reverse(st.begin(),st.end());
    return st;
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<shortestCommonSupersequence(s,t)<<endl;
    return 0;
}
/**

abac
cab

*/
