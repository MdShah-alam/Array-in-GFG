#include<bits/stdc++.h>
using namespace std;

string substring(string &s, string &t)
{
     int n=s.size();
     int m=t.size();
     if(n==0 || m==0) return "";
     int i=0,j=0,len=0,start=0,k=0;
     bool found =false;
     while(i<n && j<m){
        if(s[i]==t[j]){
            if(found==false){
                k=i;
                found=true;
            }
            int l = i-k+1;
            if(l>len){
                len=l;
                start=k;
                cout<<k<<endl;
            }
        }
        else
            found=false;
        i++;
        j++;
     }
     string ans = s.substr(start,len);
     return ans;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<substring(s,t)<<endl;
    return 0;
}
/**

abcde
abfce

*/
