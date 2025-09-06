#include<bits/stdc++.h>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int total=0, curr=0,start=0;
    for(int i=0;i<n;i++){
        int diff = gas[i]-cost[i];
        total+=diff;
        curr+=diff;
        if(curr<0){
            start=i+1;
            curr=0;
        }
    }
    return total>=0?start:-1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>gas(n),dis(n);

    for(int i=0;i<n;i++)
        cin>>gas[i];

    for(int i=0;i<n;i++)
        cin>>dis[i];

    cout<<startStation(gas,dis)<<endl;
    return 0;
}
/**

4
4 5 7 4
6 6 3 5

2
3 9
7 6

*/
