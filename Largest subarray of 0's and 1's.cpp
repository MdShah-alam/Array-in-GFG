#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&v)
{
    unordered_map<int,int>prefix_sum_index;
    int sum=0,maxlen=0;
    for(int i=0;i<v.size();i++){
        int val = (v[i]==0)?-1:1;
        sum+=val;
        if(sum == 0)
            maxlen = i+1;
        if(prefix_sum_index.find(sum) != prefix_sum_index.end()){
            int prevIndex = prefix_sum_index[sum];
            maxlen = max(maxlen , i - prevIndex);
        } else
            prefix_sum_index[sum] = i;
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
    cout<<maxLen(v)<<endl;
    return 0;
}
