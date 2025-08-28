#include<bits/stdc++.h>
using namespace std;

int const N=1e5+4;
vector<int>adj_list[N];
vector<bool>visited(N,false);

void dfs(int src)
{
    cout<<src<<" ";
    visited[src]=true;
    for(int adj_node : adj_list[src]){
        if(!visited[adj_node]){
            dfs(adj_node);
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);
}
/**
            7
            |
            |
1-----2-----3----5
      |     |
      |     |
      6-----4

node=6
edge=6
1 2 6 3 4 5
1 4 2 3 6 5

7 7
1 2
2 6
2 3
3 4
3 7
3 5
4 6

*/

