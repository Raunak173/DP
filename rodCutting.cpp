#include <bits/stdc++.h>
using namespace std;

int maxProfit(int *prices,int n,int dp[]){

    //Base case:
    if(n<=0) return 0;

    //Look up:
    if(dp[n]!=0) return dp[n];

    //rec case:
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int cut = i+1;
        int cur_ans = prices[i]+maxProfit(prices,n-cut,dp);
        ans = max(ans,cur_ans);
    }

    return dp[n] = ans;
}

int main(){

    int prices[]={1,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);

    int dp[n+1]={0};

    cout<<maxProfit(prices,n,dp)<<endl;

    return 0;
}