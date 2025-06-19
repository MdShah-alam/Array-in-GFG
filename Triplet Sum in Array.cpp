#include<bits/stdc++.h>
using namespace std;

bool hasTripletSum(vector<int> &v, int t)
{
    int n = v.size();
    sort(v.begin() , v.end());
    for(int i=0;i<n-2;i++){
        int l = i+1;
        int r = n-1;
        while(r>l){
            int sum = v[i]+v[l]+v[r];
            if(sum==t) return true;
            else if(sum>t)r--;
            else l++;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int triplet=0;
    cin>>triplet;
    cout<<hasTripletSum(v,triplet)<<endl;
    return 0;
}
/**

6
1 4 45 6 10 8
13

arr[] = [1, 4, 45, 6, 10, 8], target = 13
*/
