#include<bits/stdc++.h>
using namespace std;

int maxlen(vector<int>&A,int n)
{
    unordered_map<int ,int>mp;
    int sum=0;
    mp[0]=-1;
    int globallen=0;

    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(mp.find(sum)!=mp.end())
        {
            globallen=max(globallen,i-mp[sum]);
            continue;
        }
        mp[sum]=i;
    }
    return globallen;
}

int main()
{
    int n;
    cin>>n;

    vector<int>vc;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vc.push_back(a);
    }

    cout<<maxlen(vc,n)<<endl;


    return 0;
}
