#include<bits/stdc++.h>
using namespace std;

int const N=1e5+4;
vector<int>adj_list[N];
vector<bool>visited(N,false);
vector<int>bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    vector<int>ans;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(int adj_node : adj_list[curr]){
            if(!visited[adj_node]){
                visited[adj_node]=true;
                q.push(adj_node);
            }
        }
    }
    return ans;
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

    vector<int>k=bfs(1);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
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
