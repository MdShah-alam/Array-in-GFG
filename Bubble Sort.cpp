#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&v)
{
    int n = v.size();
    for(int i=n;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
        for(int k=0;k<n;k++)
            cout<<v[k]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    bubbleSort(v);
}
/**

5
4 1 3 9 7

*/
