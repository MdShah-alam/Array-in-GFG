#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &v, int t)
{
    int n=v.size();
    int i=0,j=1;
    if(t==v[0])
        return {1,1};
    int sum=v[0];
    while(j<n){
        sum+=v[j];
        if(sum>t){
            while(sum>t && i<=j){
                sum-=v[i];
                i++;
            }
        }

        if(sum==t){
            return {i+1,j+1};
        }

        j++;
    }
    return {-1};
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    vector<int>k = subarraySum(v,target);
    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
/**

5
1 2 3 7 5
12

10
1 2 3 4 5 6 7 8 9 10
15

7
5 1 24 15 12 41 1
5

*/
