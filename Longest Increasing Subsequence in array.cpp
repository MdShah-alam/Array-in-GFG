#include<bits/stdc++.h>
using namespace std;

int lCSA(vector<int>&v)
{
    vector<int>sub;
    for(int x : v){
        auto it = lower_bound(sub.begin(),sub.end(), x);
        if(it==sub.end()){
            sub.push_back(x);
        }
        else{
            *it = x;
        }
    }
    for(int x : sub)
        cout<<x<<" ";
    cout<<endl;
    return sub.size();
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<lCSA(v)<<endl;
    return 0;
}
/**

8
10 9 2 5 3 7 101 18

*/
