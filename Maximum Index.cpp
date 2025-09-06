#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(vector<int>&v)
{
    int n=v.size();
    vector<int>rightmax(n);
    rightmax[n-1]=v[n-1];
    int val = v[n-1];

    for(int i=n-1;i>=0;i--){
        val = max(val,v[i]);
        rightmax[i]=val;
    }

    int ans=0;
    int i=0,j=0;
    while(j<n && i<n){
        if(v[i]<=rightmax[j]){
            ans = max(ans,j-i);
            j++;
        }
        else i++;
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

    cout<<maxIndexDiff(v)<<endl;
    return 0;
}
/**

9
34 8 10 3 2 80 30 33 1

*/
