#include<bits/stdc++.h>
using namespace std;

vector<int>findMajority(vector<int>& v)
{
    int n=v.size();
    int cont=0,cont2=0;
    int cand=0, cand2=0;
    for(int x : v){
        if(x==cand)
            cont++;
        else if(x==cand2)
            cont2++;
        else if(cont==0){
            cand=x;
            cont=1;
        }
        else if(cont2==0){
            cand2=x;
            cont2=1;
        }
        else{
            cont--;
            cont2--;
        }
    }

    cont=0,cont2=0;
    for(int x : v){
        if(x==cand) cont++;
        else if(x==cand2) cont2++;
    }

    vector<int>ans;
    if(cont>n/3) ans.push_back(cand);
    if(cont2>n/3) ans.push_back(cand2);

    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>k = findMajority(v);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
