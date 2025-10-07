#include<bits/stdc++.h>
using namespace std;

string LCS(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    if(n==0||m==0) return "";
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string st="";
    while(n&&m){
        if(s[n-1]==t[m-1]){
            st+=s[n-1];
            n--;
            m--;
        }
        else{
            if(dp[n-1][m]>dp[n][m-1])
                n--;
            else
                m--;
        }
    }
    reverse(st.begin(),st.end());
    return st;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t)<<endl;
    return 0;
}
