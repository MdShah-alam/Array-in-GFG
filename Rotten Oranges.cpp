#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>&mat)
{
    int n=mat.size(),m=mat[0].size();
    queue<pair<int,int>>q;
    int fresh=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==2)
                q.push({i,j});
            else if(mat[i][j])
                fresh++;
        }
    }
    if(fresh==0) return 0;

    int minute=0;
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

    while(!q.empty()){
        int siz = q.size();
        bool rotted = false;

        for(int i=0;i<siz;i++){
            auto[x,y]=q.front();
            q.pop();
            for(auto[dx,dy]:directions){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1){
                    mat[nx][ny]=2;
                    fresh--;
                    rotted=true;
                    q.push({nx,ny});
                }
            }
        }
        if(rotted)
            minute++;
    }
    return fresh==0 ? minute:-1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }

    cout<<orangesRotting(mat)<<endl;
    return 0;
}

/**

3 3
2 1 1
1 1 0
0 1 1

*/
