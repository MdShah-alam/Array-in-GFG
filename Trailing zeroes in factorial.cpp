#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n)
{
    int ans=0;
    for(int i=5;n/i>1;i*=5)
        ans+=n/i;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<trailingZeroes(n)<<endl;
}
