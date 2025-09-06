#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    vector<int>dp(n);
    dp[0]=1;
    int p1=0,p2=0,p3=0;
    for(int i=1;i<n;i++){
        int twomultiple = dp[p1]*2;
        int threemultiple = dp[p2]*3;
        int fivemultiple = dp[p3]*5;

        dp[i] = min({twomultiple, threemultiple, fivemultiple});

        if(twomultiple==dp[i]) p1++;
        if(threemultiple==dp[i]) p2++;
        if(fivemultiple==dp[i]) p3++;
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    cout<<nthUglyNumber(n)<<endl;
    return 0;
}
