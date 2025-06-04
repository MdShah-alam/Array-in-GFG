#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>&v, int k)
{
    int n = v.size();
    unordered_map<int,int>mp;
    mp[0]=-1;
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if(mp.find(sum-k)!=mp.end())
            ans = max(ans, i-mp[sum-k]);
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
    }
    return ans;
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
    cout<<longestSubarray(v,k)<<endl;
}

/**

6
10 5 2 7 1 -10
15

*/
