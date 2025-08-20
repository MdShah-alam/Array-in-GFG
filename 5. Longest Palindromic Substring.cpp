#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n=s.size();
    if(n==0) return "";
    int start=0,maxlen=1;

    for(int i=0;i<n;i++){
        int l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > maxlen){
                start=l;
                maxlen=r-l+1;
            }
            l--;
            r++;
        }
        l=i,r=i+1;
        while(i>=0 && r<n && s[l]==s[r]){
            if(r-l+1>maxlen){
                start=l;
                maxlen=r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(start,maxlen);
}
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}
