#include<bits/stdc++.h>
using namespace std;

int palindromeSubStrs(string s)
{
    unordered_set<string>palset;
    int n=s.size();

    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            palset.insert(s.substr(l,r-l+1));
            l--;
            r++;
        }
        l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            palset.insert(s.substr(l,r-l+1));
            l--;
            r++;
        }
    }
    return palset.size();
}
//  mdnvznwlylygvstwarpibrfgvdhkdcrlmfgqweveqyoqximhubwsfahcmfhvruymazuslljbqlhswxqqpgayplxupvihucfbmwza
int main()
{
    string s;
    cin>>s;
    cout<<palindromeSubStrs(s)<<endl;
    return 0;
}
