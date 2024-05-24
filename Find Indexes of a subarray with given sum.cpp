#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    long long cs=0;
    int l=0,r=0;
    bool found=false;
    if(s==0){
        for(int i=0;i<n;i++){
            if(arr[i]==s){
                found=true;
                r=i+1;
                break;
            }
        }
    }
    if(s==0){
        if(found){
            return {r,r};
        }
        else
            return {-1};
    }

    while(r<=n){
        if(cs==s){
            found=true;
            break;
        }
        else if(cs<s){
            cs+=arr[r];
            r++;
        }
        else{
            cs-=arr[l];
            l++;
        }
    }
    if(found) return {l+1,r};
    return {-1};
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    long long s;
    cin>>s;
    vector<int>vr=subarraySum(v,n,s);

    for(int i=0;i<vr.size();i++){
        cout<<vr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
