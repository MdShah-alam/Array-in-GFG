#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string& s, string& t)
{
    int a=0,b=0,i=0,j=0;
    bool flag = true;
    if(s[0]=='-'){
        i++;
        flag = false;
    }
    while(i<s.size()){
        int k = s[i]-'0';
        a = a*10 + k;
        i++;
    }
    if(t[j]=='-'){
        j++;
        if(flag)
            flag = false;
        else
            flag = true;
    }
    while(j<t.size()){
        int k = t[j]-'0';
        b = b*10 + k;
        cout<<k<<" "<<b<<" "<<j<<endl;
        j++;
    }
    int multi = a*b;
    cout<<multi<<" "<<a<<" "<<b<<endl;
    if(multi==0) return "0";
    if(flag){
        string ans = "";
        while(multi){
            int a = multi%10;
            char ch = a+'0';
            ans+=ch;
            multi = multi/10;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    string ans = "";
    while(multi){
        int a = multi%10;
        char ch = a+'0';
        ans+=ch;
        multi = multi/10;
    }
    ans+="-";
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<multiplyStrings(s,t)<<endl;
    return 0;
}
/**

0033
2

*/
