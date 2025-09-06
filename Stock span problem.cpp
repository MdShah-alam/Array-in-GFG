#include<bits/stdc++.h>
using namespace std;

vector<int>calculateSpan(vector<int>& arr)
{
    int n = arr.size();
    vector<int>v(n);
    v[0]=1;
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i])
            st.pop();
        if(st.empty())
            v[i]=i+1;
        else
            v[i]=i-st.top();
        st.push(i);
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>k = calculateSpan(v);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
}
/**

7
100 80 60 70 60 75 85

*/
