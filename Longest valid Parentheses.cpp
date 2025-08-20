#include<bits/stdc++.h>
using namespace std;

int maxLength(string& s)
{
    stack<int>st;
    int ans=0;
    if(s=="") return ans;
    st.push(-1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            st.push(i);
        else{
            st.pop();
            if(st.empty())
                st.push(i);
            else{
                int len = i-st.top();
                ans = max(ans, len);
            }
        }
    }
    return ans;
}

int maxlenghtUpdate(string &s)
{
    int open=0,close=0;
    if(s=="") return close;
    int ans = 0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            open++;
        else
            close++;
        if(open==close)
            ans = max(ans, open+close);
        else if(close>open){
            open=0;
            close=0;
        }
    }
    close=0,open=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='(')
            open++;
        else
            close++;
        if(open==close)
            ans = max(ans, open+close);
        else if(close<open){
            open=0;
            close=0;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<maxLength(s)<<endl;
    cout<<maxlenghtUpdate(s)<<endl;
    return 0;
}
