#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string &s)
{
    int n=s.size();
    string res="";
    int reslen = 0;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>reslen){
                res=s.substr(l ,r - l + 1);
                reslen = r-l+1;
            }
            l--;
            r++;
        }
        l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>reslen){
                res=s.substr(l ,r - l + 1);
                reslen = r-l+1;
            }
            l--;
            r++;
        }
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
