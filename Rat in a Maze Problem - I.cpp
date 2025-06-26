#include<bits/stdc++.h>
using namespace std;

void solve(int i, int j,int n, vector<string>&ans,string s ,vector<vector<int>>maze,vector<vector<int>>&vis)
{
    if(i==n-1 && j==n-1){
        ans.push_back(s);
        return ;
    }
    //downword
    if(i+1<n && !vis[i+1][j] && maze[i+1][j] == 1){
        vis[i][j]=1;
        solve(i+1,j,n,ans,s+"D",maze,vis);
        vis[i][j]=0;
    }

    //left
    if(j-1>=0 && !vis[i][j-1] && maze[i][j-1] == 1){
        vis[i][j]=1;
        solve(i,j-1,n,ans,s+"L",maze,vis);
        vis[i][j]=0;
    }

    //Right
    if(j+1<n && !vis[i][j+1] && maze[i][j+1] == 1){
        vis[i][j]=1;
        solve(i,j+1,n,ans,s+"R",maze,vis);
        vis[i][j]=0;
    }

    //Up
    if(i-1>=0 && !vis[i-1][j] && maze[i-1][j] == 1){
        vis[i][j]=1;
        solve(i-1,j,n,ans,s+"U",maze,vis);
        vis[i][j]=0;
    }
}
vector<string> ratInMaze(vector<vector<int>>& maze)
{
    int n = maze.size();
    vector<string>ans;
    vector<vector<int>>vis(n,vector<int>(n,0));
    if(maze[0][0]==1) solve(0,0,n,ans,"",maze,vis);
    return ans;
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
    vector<string>st = ratInMaze(v);
    for(string s : st)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
/**

4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

*/
