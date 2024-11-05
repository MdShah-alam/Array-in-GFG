#include<bits/stdc++.h>
using namespace std;

int dp[35];
int nthFibonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=nthFibonacci(n-1)+nthFibonacci(n-2);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<nthFibonacci(n)<<endl;

    return 0;
}
