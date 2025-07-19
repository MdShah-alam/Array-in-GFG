#include<bits/stdc++.h>
using namespace std;

 int maxOnes(vector<int>& v, int k)
{
    int l=0,r=0;
    int zeros=0,maxlen=0;
    int n = v.size();

    while(r<n){
        if(v[r]==0)
            zeros++;
        while(k<zeros){
            if(v[l]==0)
                zeros--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<maxOnes(v,k)<<endl;
    return 0;
}

/**

11
1 0 0 1 1 0 1 0 1 1 1
2

*/
