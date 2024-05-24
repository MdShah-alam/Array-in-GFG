#include<bits/stdc++.h>
using namespace std;

bool Cycle(int src, vector<bool>&visited , vector<bool>&currVisited,vector<int>adj[])
{
    visited[src]=true;
    currVisited[src]=true;

    for(auto x:adj[src]){
        if(!visited[x]){
            if(Cycle(x,visited,currVisited,adj))
                return true;
        }
        else if(visited[x]==true && currVisited[x]==true)
            return true;
    }
    currVisited[src]=false;
    return false;
}

bool isCycle(int V, vector<int>adj[])
{
    vector<bool>visited(V,false), currVisited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(Cycle(i,visited,currVisited,adj))
                return true;
        }
    }
    return false;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[100];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    cout<<endl<<isCycle(v,adj)<<endl;

    return 0;
}
/**

4 4

0 1
1 2
2 3
3 1

6 5
5 3
3 1
1 2
2 4
4 0


*/
