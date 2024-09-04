#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i=0,j=0,cont=0,mx=0;
    while(i<n){
        if(arr[i]<=dep[j]){
            cont++;
            i++;
        }
        else{
            cont--;
            j++;
        }
        mx=max(cont,mx);
    }
    return mx;
}

int main()
{
    int n;
    cin>>n;
    int ar[n],dp[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<n;i++){
        cin>>dp[i];
    }
    cout<<findPlatform(ar,dp,n)<<endl;
    return 0;
}

//6
//0900 0940 0950 1100 1500 1800
//0910 1200 1120 1130 1900 2000
