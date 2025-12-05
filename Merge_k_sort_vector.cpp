#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    vector<vector<int>>v;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        vector<int>demo(n);
        for(int j=0;j<n;j++)
            cin>>demo[j];
        v.push_back(demo);
    }
    vector<int>Tracer(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<k;i++){
        pq.push({v[i][0],i});
    }
    vector<int>ans;
    while(!pq.empty()){
        auto z = pq.top();
        pq.pop();
         int x = z.first;
         int i = z.second;
         ans.push_back(x);
         int ind = Tracer[i]+1;
         if(ind<v[i].size()){
            pq.push({v[i][ind],i});
            Tracer[i]=ind;
         }
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/**

3
3
1 4 7
2
3 5
3
2 4 6

*/
