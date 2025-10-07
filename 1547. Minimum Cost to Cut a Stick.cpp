#include<bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>&v)
{
    v.push_back(0);
    v.push_back(n);


}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int m;
    cin>>m;
    cout<<minCost(m,v)<<endl;
    return 0;
}
