//44
#include<bits/stdc++.h>
using namespace std;

int nthPoint(int n)
{
    if(n==1) return 1;
    const int mod=1e9+7;
    int prev2=1;
    int prev1=1;

    for(int i=2;i<=n;i++){
        int current=(prev1+prev2)%mod;
        prev1=prev2;
        prev2=current;
    }
    return prev2;
}

int main()
{
    int n;
    cin>>n;
    cout<<nthPoint(n)<<endl;
    return 0;
}
