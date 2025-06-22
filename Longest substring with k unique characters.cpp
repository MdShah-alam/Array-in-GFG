#include<bits/stdc++.h>
using namespace std;

int longestlength(string &s , int k)
{
    unordered_map<char,int>mp;
    int i=0,j=0,res=0;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
        }
        if(k>=mp.size())
            res = max(res,j-i+1);
        j++;
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<longestlength(s , k)<<endl;
    return 0;
}
