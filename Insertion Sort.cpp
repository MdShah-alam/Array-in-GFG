#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&v)
{
    int n = v.size();
    for(int i=0;i<n-1;i++){
        int res = v[i];
        int k = 0;
        for(int j=i;j<n;j++){
            if(res>v[j]){
                res = v[j];
                k=j;
            }
        }
        if(k!=0)
            swap(v[k],v[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
        cin>>v[i];
    insertionSort(v);
    return 0;
}
/**

5
4 1 3 9 7

*/
