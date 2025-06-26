#include<bits/stdc++.h>
using namespace std;

void merge_(vector<int>&a,vector<int>&v,int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid && j<=r){
        if(v[i]<v[j]){
            a[k]=v[i];
            i++;
        }
        else{
            a[k]=v[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=r){
            a[k]=v[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            a[k]=v[i];
            i++;
            k++;
        }
    }
    for(int k = l;k<=r;k++)
        v[k]=a[k];
}
void ans(vector<int>&a,vector<int>&v,int l,int r)
{
    if(l<r){
        int mid = (l+r)/2;
        ans(a,v,l,mid);
        ans(a,v,mid+1,r);
        merge_(a,v,l,mid,r);
    }
}
void mergeSort(vector<int>& v, int l, int r)
{
    vector<int>a(v.size());
    ans(a,v,l,r);
    v=a;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    mergeSort(v,0,n-1);
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

/**

9
4 6 3 1 2 7 9 8 5

*/
