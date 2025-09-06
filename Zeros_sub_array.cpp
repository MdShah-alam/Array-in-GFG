#include<bits/stdc++.h>
using namespace std;

vector<int> zeroSubArray(vector<int>&v)
{
    int n = v.size();
    int start=0,endS=0;
    unordered_map<int,int>st;
    int prefix=0;

    for(int i=0;i<n;i++){
        prefix+=v[i];
        if(st.find(prefix)!=st.end()){
            endS = i;
            start = st[prefix]+1;
            break;
        }
        st[prefix]=i;
    }

    vector<int>k;
    for(int i=start;i<=endS;i++){
        k.push_back(v[i]);
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>k = zeroSubArray(v);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
/**

5
4 2 -3 1 6

*/
