#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long>v(n);
    stack<long long>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        if(st.empty())
            v.push_back(-1);
        else
            v.push_back(st.top());
        st.push(arr[i]);
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<long long>v,v1;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }
    v1=nextLargerElement(v,n);
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}
