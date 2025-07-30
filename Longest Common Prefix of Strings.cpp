#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& v)
{
    if(v.empty()) return "";              // Edge case: empty vector
    int n = v.size();
    if(n == 1) return v[0];               // Single string case

    string prefix = v[0];                 // Start with first string

    for(int i = 1; i < n; i++) {
        string k = v[i];                  // Compare with each string
        int j = 0;
        while(j < prefix.size() && j < k.size() && prefix[j] == k[j]) {
            j++;                          // Count matching prefix chars
        }
        prefix = prefix.substr(0, j);     // Cut the prefix
        if(prefix.empty()) return "";     // Early exit if no common prefix
    }
    return prefix;
}


int main()
{
    int n;
    cin>>n;
    vector<string>st(n);
    for(int i=0;i<n;i++)
        cin>>st[i];
    cout<<longestCommonPrefix(st)<<endl;
    return 0;
}
/**

4
geeksforgeeks geeks geek geezer

*/
