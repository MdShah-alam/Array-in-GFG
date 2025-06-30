#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string &s)
{
    int freq[26]={0};
    queue<char>q;
    string result="";
    for(char ch : s){
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }
        if(!q.empty())
            result += q.front();
        else
            result+='#';
    }
    return result;
}

int main()
{
    string s;
    cin>>s;
    cout<<FirstNonRepeating(s)<<endl;
    return 0;
}
