#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>&v)
{
    vector<int>temp;
    temp.push_back(v[0]);
    int len=1;
    for(int i=1;i<v.size();i++){
        if(v[i]>temp.back()){
            temp.push_back(v[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin() , temp.end(),v[i])-temp.begin();
            temp[ind] = v[i];
        }
    }
    return len;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<lis(v)<<endl;
    return 0;
}

/**

16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

*/
