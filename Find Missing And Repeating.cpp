#include<bits/stdc++.h>
using namespace std;

vector<int>repeatmissing(vector<int>arr , int n)
{
    bool v[n+1] = {false};
    vector<int>k;

    int repeating , missing;

    for(int i=0;i<n;i++){
        if(v[arr[i]]==true){
            repeating=arr[i];
        }
        v[arr[i]]=true;
    }

    for(int i=1;i<=n;i++){
        if(v[i]==false){
            missing=i;
            break;
        }
    }

    k.push_back(repeating);
    k.push_back(missing);
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector<int>k=repeatmissing(v , n);

    for(int i=0;i<2;i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
}
