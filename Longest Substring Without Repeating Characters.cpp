#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int l=0,r=0 , res=0;
    vector<bool>v(26,false);
    while(r<s.size()){
        char ch = tolower(s[r]);
        while(v[ch-'a']==true){
            v[tolower(s[l])-'a']=false;
            l++;
        }
        v[ch-'a']=true;

        res = max(res,r-l+1);

        r++;
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
