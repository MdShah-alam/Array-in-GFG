#include<bits/stdc++.h>
using namespace std;

int countOfSubstrings(string s, int k)
{
    vector<int>v(26,0);
    int n=s.size(),res=0;
    for(int i=0;i<k-1;i++)
        v[s[i]-'a']++;

    for(int i = k-1;i<n;i++){
        v[s[i]-'a']++;
        int dist=0;
        for(int i=0;i<26;i++){
            if(v[i]>0)
                dist++;
        }
        if(dist==k-1)
            res++;
        v[s[i-k+1]-'a']--;
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<countOfSubstrings(s,k)<<endl;
    return 0;
}
