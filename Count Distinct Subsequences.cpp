#include<bits/stdc++.h>
using namespace std;

void generateSubseq(int ind , string &s, string &curr, set<string>&st)
{
    if(ind==s.size()){
        st.insert(curr);
        return ;
    }
    generateSubseq(ind+1,s,curr,st);
    curr.push_back(s[ind]);
    generateSubseq(ind+1,s,curr,st);
    curr.pop_back();
}
int distinctSubseq(string &s)
{
    set<string>st;
    string curr="";
    generateSubseq(0,s,curr,st);
    int n = st.size();
    for(string sk : st)
        cout<<sk<<" ";
    cout<<endl;
    return n;
}

int main()
{
    string s;
    cin>>s;
    cout<<distinctSubseq(s)<<endl;
    return 0;
}
