#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& v, int t)
{
    int n=v.size();
    sort(v.begin(),v.end());
    int closestSum = v[0]+v[1]+v[2];

    for(int i=0;i<n-2;i++){
        int j=i+1,k=n-1;
        while(j<k){
            int sum = v[i]+v[j]+v[k];
            if(abs(sum-t)<abs(closestSum-t))
                closestSum=sum;
            if(sum>t) k--;
            else if(sum<t) j++;
            else return sum;
        }
    }
    return closestSum;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int t;
    cin>>t;
    cout<<threeSumClosest(v,t)<<endl;
    return 0;
}
/**

4
-1 2 1 -4
1

*/
