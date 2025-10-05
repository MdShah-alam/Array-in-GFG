#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>&v, int n, int t, vector<vector<bool>>&dp)
{
    if(t==0) return true;
    if(n==0) return false;
    if(dp[n][t]!=false) return dp[n][t];
    if(t>=v[n-1])
        return dp[n][t] = fun(v,n-1,t-v[n-1],dp) || fun(v,n-1,t,dp);
    else
        return dp[n][t] = fun(v,n-1,t,dp);
}
bool subset(vector<int>&v,int sum)
{
    int n=v.size();

//    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
//    return fun(v,n,sum,dp);

    bool arr[n+1][sum+1];

    for(int i=0;i<=sum;i++)
        arr[0][i]=false;

    for(int i=0;i<n+1;i++)
        arr[i][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=v[i-1])
                arr[i][j] = arr[i-1][j-v[i-1]] || arr[i-1][j];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][sum];
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int sum;
    cin>>sum;
    cout<<subset(v,sum)<<endl;
    return 0;
}
/**

5
2 3 7 8 10
11

*/
