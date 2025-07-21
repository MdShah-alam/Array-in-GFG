#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int>res;
    res.push_back(1);
    for(int i=2;i<=n;i++){
        int carry=0;
        for(int j=0;j<res.size();j++){
            int digit = res[j]*i+carry;
            res[j]=digit%10;
            carry = digit/10;
        }
        while(carry){
            res.push_back(carry%10);
            carry = carry/10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v=factorial(n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
