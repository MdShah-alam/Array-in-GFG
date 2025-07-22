#include<bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n,int e, int a[], int b[])
{
    unordered_map<int,stack<int>>m;
    for(int i=0;i<2*e;i+=2){
        m[a[i]].push(a[i+1]);
    }
    for(int i=0;i<2*e;i+=2){
        if(m[b[i]].top()!=b[i+1]) return 0;
        m[b[i]].pop();
    }
    return 1;
}

int main()
{
    int n,e;
    cin>>n>>e;
    int a[2*e],b[2*e];

    for(int i=0;i<2*e;i++)
        cin>>a[i];

    for(int i=0;i<2*e;i++)
        cin>>b[i];

    cout<<checkMirrorTree(n,e,a,b)<<endl;
    return 0;

}
/**

3 2
1 2 1 3
1 3 1 2

*/
