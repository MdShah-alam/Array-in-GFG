#include<bits/stdc++.h>
using namespace std;

bool help(vector<int>&v,int x)
{
    int n=v.size();
    int l=0,r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(v[mid]==x) return true;
        else if(v[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>&mat, int x)
{
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        if(x>=mat[i][0] && x<=mat[i][m-1]){
            vector<int>v=mat[i];
            return help(v,x);
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }

    int x;
    cin>>x;
    cout<<searchMatrix(v,x)<<endl;
    return 0;
}
/**

3 3
1 5 9
14 20 21
30 34 43
14

*/
