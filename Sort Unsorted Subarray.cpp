#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2; // Default to 0 length if already sorted
        int minRight = nums[n - 1];
        int maxLeft = nums[0];

        for (int i = 1; i < n; i++) {
            maxLeft = max(maxLeft, nums[i]);
            if (nums[i] < maxLeft) {
                end = i;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            minRight = min(minRight, nums[i]);
            if (nums[i] > minRight) {
                start = i;
            }
        }

        return end - start + 1;
    }

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<findUnsortedSubarray(v)<<endl;
    return 0;
}
/**

7
2 6 4 8 10 9 15

*/
