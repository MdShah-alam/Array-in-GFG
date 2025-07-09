#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(vector<int>&v)
{
    int n = v.size();
    vector<int>prefix(n),suffix(n);
    prefix[0]=v[0];
    suffix[n-1]=v[n-1];

    for(int i = 1; i < n; i++)
        prefix[i] = min(prefix[i-1], v[i]);

    for(int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i+1], v[i]);

    int ans=0,i=0,j=0;
    while(j<n && i<n){
        if(prefix[i]<=suffix[j]){
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
