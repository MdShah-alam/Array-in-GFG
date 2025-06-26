#include<bits/stdc++.h>
using namespace std;

vector<int>spirallyTraverse(vector<vector<int>>mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;
    vector<int>v;

while (top <= bottom && left <= right) {
    // 1. Traverse Left → Right
    for (int i = left; i <= right; i++)
        v.push_back(mat[top][i]);
    top++;

    // 2. Traverse Top ↓ Bottom
    for (int i = top; i <= bottom; i++)
        v.push_back(mat[i][right]);
    right--;

    // 3. Traverse Right → Left (only if still within bounds)
    if (top <= bottom) {
        for (int i = right; i >= left; i--)
            v.push_back(mat[bottom][i]);
        bottom--;
    }

    // 4. Traverse Bottom ↑ Top (only if still within bounds)
    if (left <= right) {
        for (int i = bottom; i >= top; i--)
            v.push_back(mat[i][left]);
        left++;
    }
}

    return v;
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
    vector<int>k = spirallyTraverse(v);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

/**

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 15

*/
