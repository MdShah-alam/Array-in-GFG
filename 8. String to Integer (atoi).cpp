#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int n = s.size();
    int i=0;
    if(s.empty()) return 0;
    while(i<n && s[i]==' ') i++;
    int sign=1;
    if(i<n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-')
            sign=-1;
        i++;
    }
    long long ans=0;
    while(i<n && isdigit(s[i])){
        ans = ans*10 + (s[i]-'0');
        if(ans*sign >INT_MAX) return INT_MAX;
        if(ans*sign<INT_MIN) return INT_MIN;
        i++;
    }
    return (int)(ans*sign);
}

int main()
{
    string s;
    cin>>s;
    cout<<myAtoi(s)<<endl;
    return 0;
}
