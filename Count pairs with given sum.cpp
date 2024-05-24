#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    int ans=0;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        int val = k - arr[i];
        if(val<=0) continue;
        if(mp[val]){
            ans+=mp[val];
        }
        mp[arr[i]]++;
    }
    return ans;
}

int main()
{
    int n , k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getPairsCount(arr,n,k)<<endl;
    return 0;
}
