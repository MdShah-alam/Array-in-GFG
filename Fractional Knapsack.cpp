#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2; // sort in decreasing order of value/weight
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
{
    vector<pair<int,int>>vp;
    for(int i=0;i<val.size();i++){
        vp.push_back({val[i],wt[i]});
    }
    sort(vp.begin(),vp.end(),cmp);

    double ans=0.0;

    for(int i=0;i<val.size();i++){
        if(vp[i].second<=capacity){
            ans+=vp[i].first;
            capacity-=vp[i].second;
        }
        else{
            ans += (double)vp[i].first * ((double)capacity / (double)vp[i].second);
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    int cap;
    cin>>cap;
    cout<<fractionalKnapsack(val,wt,cap)<<endl;
    return 0;
}
/**

3
60 100 120
10 20 30
50

*/
