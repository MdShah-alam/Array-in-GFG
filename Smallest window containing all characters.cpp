#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string &s, string &t)
{
    int n=s.size();
    int m=t.size();
    if(m>n) return "";
    unordered_map<char,int>need;
    for(char ch : t) need[ch]++;

    unordered_map<char,int>have;
    int required = need.size();
    int formed=0;

    int l=0,r=0;
    int minLen=INT_MAX, startIdx=-1;

    while(r<n){
        char ch = s[r];
        have[ch]++;

        if(need.find(ch)!=need.end() && have[ch] == need[ch])
            formed++;

        while(l<=r && formed==required){
            if(r-l+1<minLen){
                minLen = r-l+1;
                startIdx = l;
            }

            char leftChar = s[l];
            have[leftChar]--;
            if(need.find(leftChar) != need.end() && have[leftChar] < need[leftChar])
                formed--;

            l++;
        }
        r++;
    }
    return (startIdx == -1) ? "" : s.substr(startIdx,minLen);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<smallestWindow(s,t)<<endl;
    return 0;
}

/**

timetopractice
toc

*/
