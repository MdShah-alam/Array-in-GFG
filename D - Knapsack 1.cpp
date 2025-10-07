#include<bits/stdc++.h>
using namespace std;

int help(int w, int n, vector<int>&wt, vector<int>&val, vector<vector<long long int>>&dp)
{

}
long long int knapsack(int w , vector<int>&wt, vector<int>&val)
{
    int n = val.size();
    vector<vector<long long int>>dp(n+1,vector<long long int>(w+1,-1));
    return help(w,n,wt,val,dp);
}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>wt(n),val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    cout<<knapsack(w,wt,val)<<endl;
    return 0;
}
