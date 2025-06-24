#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>&v)
{
    set<vector<int>>st;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int k=0;k<n-2;k++){
        int i=k+1,j=n-1;
        while(j>i){
            int sum = v[k]+v[i]+v[j];
            if(sum==0){
                st.insert({v[k],v[i],v[j]});
                i++;
                j--;
            }
            else if(sum>0) j--;
            else i++;
        }
    }
    vector<vector<int>>ans;
    for(vector<int>x : st)
        ans.push_back(x);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<int>>ans = threeSum(v);
    for(vector<int>x : ans){
        for(int val : x)
            cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}
/**

6
-1 0 1 2 -1 -4

*/
