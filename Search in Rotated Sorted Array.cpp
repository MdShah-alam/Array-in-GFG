#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&v, int target)
{
    int n = v.size();
    int left = 0, right = n-1;

    while(left<=right){
        int mid = left + (right-left)/2;
        if(v[mid] == target) return mid;
        else if(v[left]<=v[mid]){
            if(target>=v[left] && target<v[mid])
                right = mid -1;
            else
                left = mid+1;
        }
        else{
            if(target<=v[right] && target>v[mid])
                left = mid+1;
            else
                right = mid-1;
        }
    }
    return -1;
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
    cout<<search(v,target)<<endl;
    return 0;
}

/**

9
5 6 7 8 9 10 1 2 3
3

*/
