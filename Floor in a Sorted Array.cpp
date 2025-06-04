#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x)
{
    int k=-1;
    int i=0, j=arr.size()-1;
    while(i<=j)
    {
        int mid = i+(j-i)/2;
        //cout<<arr[mid]<<" "<<mid<<endl;
        if(arr[mid]<=x)
        {
            k = mid;
        }
        if(arr[mid]>x)
        {
            j=mid-1;
        }
        else i=mid+1;
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<findFloor(v,k)<<endl;
    return 0;
}
