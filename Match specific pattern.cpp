#include<bits/stdc++.h>
using namespace std;

vector<string>findMatchedWords(int n, vector<string> dict, string pattern) {
    vector<string>st;
    for(string s : dict){
        if(s.size()!=pattern.size()) continue;
        unordered_map<char,int>ss,pt;
        for(int i=0;i<pattern.size();i++){
            ss[s[i]]++;
            pt[pattern[i]]++;
        }
        bool found = true;
        vector<int>a,b;
        for(char ch='a';ch<='z';ch++){
            if(ss[ch]!=0)
                a.push_back(ss[ch]);
            if(pt[ch]!=0)
                b.push_back(pt[ch]);
        }
        if(a.size()!=b.size()) continue;
        if(a==b) st.push_back(s);
    }
    return st;
}

int main()
{
    int n;
    cin>>n;
    vector<string>st(n);
    for(int i=0;i<n;i++)
        cin>>st[i];

    string pattern;
    cin>>pattern;
    vector<string>v = findMatchedWords(n,st,pattern);
    for(string s : v)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}

/**

4
abb abc xyz xyy
foo

*/
