#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
int happiness[N][4], dp[N][4];

int fun(int day, int current_task)
{
    if(day==1) return happiness[day][current_task];
    if(dp[day][current_task]!=-1) return dp[day][current_task];
    int max_profit = 0;
    for(int last_task=1;last_task<=3;last_task++){
        if(last_task!=current_task){
            int current_candiate = happiness[day][current_task]+fun(day-1,last_task);
            max_profit = max(current_candiate,max_profit);
        }
    }
    return dp[day][current_task]=max_profit;
}
int main()
{
    int day;
    cin>>day;
    for(int i=1;i<=day;i++){
        for(int j=1;j<4;j++)
            cin>>happiness[i][j];
    }
    for(int i=1;i<=day;i++){
        for(int j=1;j<4;j++)
            dp[i][j]=-1;
    }
    int ans1 = fun(day,1);
    int ans2 = fun(day,2);
    int ans3 = fun(day,3);

    cout<<max({ans1,ans2,ans3})<<endl;
    return 0;
}
