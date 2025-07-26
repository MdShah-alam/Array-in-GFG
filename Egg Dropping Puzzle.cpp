#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int res(int n, int k)
{
    if(k==0 || k==1) return k;
    if(n==1) return k;

    if(dp[n][k]!=-1) return dp[n][k];

    int ans = INT_MAX;
    int l=1, h=k;
    while(l<=h){
        int mid = (l+h)/2;

        int break_case = res(n-1 , mid-1);
        int not_break_case = res(n, k-mid);

        int worst = 1+max(break_case, not_break_case);
        ans = min(ans, worst);

        if(break_case > not_break_case)
            h=mid-1;
        else
            l=mid+1;
    }

    return dp[n][k]=ans;
}
int eggDrop(int n, int k)
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++)
            dp[i][j]=-1;
    }
    return res(n,k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<eggDrop(n,k)<<endl;
    return 0;
}
/**

2 36

3 36

*/
