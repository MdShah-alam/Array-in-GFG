#include<bits/stdc++.h>
using namespace std;

vector<int>kLargest(vector<int>&v, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int x : v){
        if(pq.size()==k){
            if(pq.top()<x){
                pq.pop();
                pq.push(x);
            }
        }
        else
            pq.push(x);
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int num;
    cin>>num;
    vector<int>k = kLargest(v,num);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
/**

5
12 5 787 1 23
2

*/
