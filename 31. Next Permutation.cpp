#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&v)
{
    int indx=-1;
    int n = v.size();
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            indx=i;
            break;
        }
    }
    if(indx==-1){
        reverse(v.begin(),v.end());
        return ;
    }
    bool found=true;
    while(found){
        for(int i=n-1;i>=0;i--){
            if(v[indx]<v[i]){
                swap(v[indx],v[i]);
                break;
            }
        }
        indx=-1;
        for(int i=n-2;i>=0;i--){
            if(v[i]<v[i+1]){
                indx=i;
                break;
            }
        }
        if(indx==-1) return ;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    nextPermutation(v);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
