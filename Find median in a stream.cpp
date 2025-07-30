#include<bits/stdc++.h>
using namespace std;

vector<double>getMedian(vector<int>&v)
{
    priority_queue<int>maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<double>k;
    for(int x : v){
        if(maxheap.empty()|| x<=maxheap.top())
            maxheap.push(x);
        else
            minheap.push(x);

        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        if(maxheap.size()>minheap.size())
            k.push_back(double(maxheap.top()));
        else{
            k.push_back((maxheap.top()+minheap.top())/2.0);
        }
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<double>k=getMedian(v);
    for(int i=0;i<n;i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
}

/**

6
5 15 1 3 2 8

*/
