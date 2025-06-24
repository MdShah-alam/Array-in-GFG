#include<bits/stdc++.h>
using namespace std;

vector<int>findUnion(vector<int>&v1,vector<int>&v2)
{
    vector<int>v;
    if(v1[0]<v2[0])
        v.push_back(v1[0]);
    else
        v.push_back(v2[0]);

    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            if(v.back()!=v1[i])
                v.push_back(v1[i]);
            i++;
        }
        else if(v1[i]>v2[j]){
            if(v.back()!=v2[j])
                v.push_back(v2[j]);
            j++;
        }
        else{
            if(v.back()!=v1[i])
                v.push_back(v1[i]);
            j++;
            i++;
        }
    }
    while(i<v1.size()){
        if(v.back()!=v1[i]) v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        if(v.back()!=v2[j]) v.push_back(v2[j]);
        j++;
    }
    return v;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v1(n),v2(m);
    for(int i=0;i<n;i++)
        cin>>v1[i];
    for(int i=0;i<m;i++)
        cin>>v2[i];
    vector<int>v = findUnion(v1,v2);
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
/**

5 5
2 2 3 4 5
1 1 2 3 4

*/
