#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums)
{
    int n=nums.size();
    vector<pair<int ,int >>v;

    for(int i=0;i<n;i++)
    {
        v.push_back({a[i],i});
    }

    sort(v.begin(),v.end());

    int c=0;

    for(int i=0;i<n;i++)
    {
        if(v[i].second!=i)
        {
            c++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    return c;
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

    cout<<minSwaps(vc);

    return 0;
}
