#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>&v)
{
    int n = v.size();
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(v[i]<v[i+1]){
            ans+=v[i+1]-v[i];
        }
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

    cout<<maximumProfit(v)<<endl;
    return 0;
}
/**

6
7 1 5 3 6 4

*/
