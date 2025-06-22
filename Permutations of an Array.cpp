#include<bits/stdc++.h>
using namespace std;

/**

void calculate(vector<int>&v, int ind, vector<vector<int>>&ans)
{
    if(ind==v.size()){
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<v.size();i++){
        swap(v[ind] , v[i]);
        calculate(v,ind+1,ans);
        swap(v[ind] , v[i]);
    }
}

vector<vector<int>> findPermutations(vector<int>v)
{
    vector<vector<int>>ans;
    calculate(v,0,ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>>ans = findPermutations(v);
    for(vector<int>k: ans){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

*/

void backtrack(string &s ,vector<bool>&used,string &path, vector<string>&ans)
{
    if(path.size() == s.size()){
        ans.push_back(path);
        return ;
    }
    for(int i=0;i<s.size();i++){
        if(used[i])continue;

        if(i>0 && s[i]==s[i-1] && !used[i-1]) continue;

        used[i]=true;
        path.push_back(s[i]);
        backtrack(s,used,path,ans);
        path.pop_back();
        used[i]=false;
    }
}

vector<string> findPermutation(string &s)
{
    vector<string>ans;
    vector<bool>used(s.size(),false);
    string path;
    sort(s.begin(),s.end());
    backtrack(s,used,path, ans);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    vector<string>v = findPermutation(s);
    for(string k : v)
        cout<<k<<" ";
    cout<<endl;
}
