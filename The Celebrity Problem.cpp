#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat)
{
    int n=mat.size();
    int a=0, b=n-1;
    while(a<b){
        if(mat[a][b]==1)
            a++;
        else b--;
    }
    int candidate = a;
    for(int i=0;i<n;i++){
        if(i!=candidate){
            if(mat[candidate][i] == 1 || mat[i][candidate] ==0 )
                return -1;
        }
    }
    return candidate;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    }
    cout<<celebrity(v)<<endl;
    return 0;
}
/**

3
1 1 0
0 1 0
0 1 1

*/
