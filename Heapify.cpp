#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v, int n, int i)
{
    int left = i*2+1;
    int right = i*2+2;
    int leargest = i;
    if(left<n && v[leargest]<v[left])
        leargest = left;
    if(right<n && v[leargest]<v[right])
        leargest = right;
    if(leargest != i){
        swap(v[i],v[leargest]);
        heapify(v,n,leargest);
    }
}
void heapSort(vector<int>&v, int n)
{
    for(int i=n-1;i>=0;i--){
        swap(v[i],v[0]);
        heapify(v,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=(n/2)-1;i>=0;i--){
        heapify(v,n,i);
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

    cout<<"After heapsort"<<endl;
    heapSort(v,n);
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
