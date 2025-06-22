#include<bits/stdc++.h>
using namespace std;

bool checkpangram(string s)
{
    for(char ch = 'a' ; ch<='z' ;ch++){
        bool found = false;
        for(int i=0;i<s.size();i++){
            char cr = tolower(s[i]);
            if(ch==cr){
                found = true;
                break;
            }
        }
        if(found==false) return false;
    }
    cout<<endl;
    return true;
}

int main()
{
    string s;
    cin>>s;
    cout<<checkpangram(s)<<endl;
}
