#include<bits/stdc++.h>
using namespace std;

void matchPairs(int n, char nuts[], char bolts[])
{
    char store[] = { '!','#','$','%','&','*','?','@','^' };
    set<char>st;
    for(int i=0;i<n;i++)
        st.insert(nuts[i]);
    int j=0;
    for(int i=0;i<9;i++){
        if(st.find(store[i])!=st.end()){
            nuts[j]=store[i];
            bolts[j]=store[i];
            j++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    char nuts[n],bolts[n];

    for(int i=0;i<n;i++)
        cin>>nuts[i];
    for(int i=0;i<n;i++)
        cin>>bolts[i];

    matchPairs(n, nuts, bolts);
    cout<<endl;

    for(int i=0;i<n;i++)
        cout<<nuts[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<bolts[i]<<" ";
    cout<<endl;

    return 0;
}
/**

5
@ % $ # ^
% @ # $ ^

n = 5, nuts[] = {@, %, $, #, ^}, bolts[] = {%, @, #, $ ^}

*/
