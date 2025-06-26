#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int>a,vector<int>b,int k)
{
    int n = a.size(), m = b.size();
    if(n>m) kthElement(b,a,k);

    int low = max(0,k-m), high = min(k,n);

    while(low<=high){
        int cut1 = (low+high)/2;
        int cut2 = k - cut1;

        int l1 = (cut1==0) ? INT_MIN : a[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];

        if(l1<=r2 && l2<=r1)
            return max(l1,l2);

        else if(l1>r2)
            high = cut1-1;

        else
            low = cut1+1;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];

    int k;
    cin>>k;
    cout<<kthElement(a,b,k)<<endl;

    return 0;
}

/**

5 4
2 3 6 7 9
1 4 8 10
5

*/
