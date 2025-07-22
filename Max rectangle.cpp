#include<bits/stdc++.h>
using namespace std;

int leargestRectangleArea(vector<int>&vv)
{
    stack<int>st;
    vv.push_back(0);
    int maxa=0;

    for(int i=0;i<vv.size();i++){
        while(!st.empty() && vv[i]<vv[st.top()]){
            int height = vv[st.top()];
            st.pop();
            int width = st.empty() ? i : i-st.top()-1;
            maxa = max(maxa , height * width);
            cout<<maxa<<" "<<height<<" "<<width<<endl;
        }
        st.push(i);
    }
    return maxa;
}

int maxArea(vector<vector<int>>&v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int>heights(m,0);
    int maxArea = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1)
                heights[j]+=1;
            else
                heights[j]=0;
        }
        maxArea = max(maxArea,leargestRectangleArea(heights));
    }
    return maxArea;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }

    cout<<maxArea(v)<<endl;
    return 0;
}

/**

4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

2 4
0 1 1 0
1 1 1 1

*/
