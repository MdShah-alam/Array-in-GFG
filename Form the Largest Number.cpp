#include<bits/stdc++.h>
using namespace std;

static bool compare(const string& a, const string& b)
{
    return a+b>b+a;
}
string findLargest(vector<int> &v)
{
    vector<string>st;
    for(int x : v){
        st.push_back(to_string(x));
    }
    sort(st.begin(),st.end(),compare);
    if(st[0]=="0")
        return "0";
    string sk="";
    for(const string& s : st)
        sk+=s;
    return sk;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<findLargest(v)<<endl;
    return 0;
}
/**

5
3 30 34 5 9

*/
