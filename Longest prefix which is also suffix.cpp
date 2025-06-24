#include<bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string &s)
{
    int n=s.size();
    vector<int>v(n);
    int len = 0;
    v[len]=0;
    for(int i=1;i<n;){
        if(s[i]==s[len]){
            len++;
            v[i]=len;
            i++;
        }
        else{
            if(len!=0)
                v[i]=v[len-1];
            else{
                v[i]=len;
                i++;
            }
        }
    }
    return v[n-1];
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPrefixSuffix(s)<<endl;
    return 0;
}
