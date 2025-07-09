#include<bits/stdc++.h>
using namespace std;

int isValid(string &s) {
    stringstream ss(s);
    string seg;
    int n=0;
    while(getline(ss,seg , '.')){
        if(seg.empty() || (seg.size()>1 && seg[0]=='0'))
            return 0;
        for(char c : seg){
            if(!isdigit(c)) return 0;
        }
        int m = stoi(seg);
        if(m<0 || m>255)
            return 0;
        n++;
    }
    if(n==4) return 1;
    else return 0;
}

int main()
{
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;
    return 0;
}
