#include<bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end)
{
    int n = start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(), [](pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second;
    });
    int ans=0;
    pair<int,int>x = v[0];
    int b = x.second;
    for(int i=1;i<n;i++){
        x = v[i];
        if(x.first>b){
            ans++;
            b = x.second;
        }
    }
    ans++;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>start(n),end(n);

    for(int i=0;i<n;i++)
        cin>>start[i];

    for(int i=0;i<n;i++)
        cin>>end[i];

    cout<<maxMeetings(start,end)<<endl;
    return 0;
}

/**

6
1 3 0 5 8 5
2 4 6 7 9 9

*/
