#include<bits/stdc++.h>
using namespace std;

bool isPossible(int barrier, vector<int>&v, int k)
{
    int student=1,pages=0;
    int n = v.size();
    for(int i=0;i<n;i++){
        if(v[i]>barrier) return false;
        if(pages+v[i]>barrier){
            pages=v[i];
            student+=1;
        }
        else
            pages+=v[i];
    }
    if(student>k) return false;
    return true;
}
int findPages(vector<int> &v, int k)
{
    int n=v.size();
    if(k>n) return -1;
    int sum=0,low=INT_MAX;
    for(int i=0;i<n;i++){
        sum+=v[i];
        low = min(v[i],low);
    }
    int high = sum,res=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(mid,v,k)){
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<findPages(v,k)<<endl;
    return 0;
}
