#include<bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<int>&v, int k)
{
    int n=v.size();
    if(k>=n)
        reverse(v.begin(),v.end());
    else{
        int i=0;
        do{
            reverse(v.begin()+i,v.begin()+min(i+k,n));
            i+=k;
        }while(i<n);
    }
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
    reverseInGroups(v,k);
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
}
