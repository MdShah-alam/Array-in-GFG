#include<bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<int>&v, vector<vector<long long>>&dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi = INT_MIN;
    for(int ind = i;ind<=j;ind++){
        maxi = max(maxi,v[i-1]*v[ind]*v[j+1]+fun(i,ind-1,v,dp)+fun(ind+1,j,v,dp));
    }
    return dp[i][j]=maxi;
}

int maxCoins(vector<int>&v)
{
    int n = v.size();
    v.push_back(1);
    v.insert(v.begin(),1);
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    return fun(1,n,v,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxCoins(v)<<endl;
    return 0;
}
/**

4
3 1 5 8

*/
