#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& array, int n)
{
    sort(array.begin(),array.end());
    if(array[0]!=1)
        return 1;

    for(int i=0;i<array.size()-1;i++){
        int a=array[i]+1;
        if(a!=array[i+1])
            return a;
    }
    return n;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<missingNumber(v,n)<<endl;
    return 0;
}
