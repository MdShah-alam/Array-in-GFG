#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(a[mid]==0){
            int tem=a[low];
            a[low]=a[mid];
            a[mid]=tem;
            mid++;
            low++;
        }
        else if(a[mid]==2){
            int tem=a[high];
            a[high]=a[mid];
            a[mid]=tem;
            high--;
        }
        else
            mid++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];

    for(int i=0;i<n;i++)
        cin>>ar[i];

    sort012(ar,n);
    return 0;
}
