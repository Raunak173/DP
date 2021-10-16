#include <bits/stdc++.h>
using namespace std;

int minCoins(int n,int coins[],int t,int dp[]){

    //Base Case:
    if(n==0) return 0;

     //Lookup in dp array:
    if(dp[n]!=0){
        return dp[n];
    }

    //Recursive Case:
    int ans=INT_MAX;
    for(int i=0;i<t;i++){
        if((n-coins[i])>=0){
            int sp = minCoins(n-coins[i],coins,t,dp); //Ans of sub problem
            ans=min(ans,sp+1);
        } 
    }
    dp[n]=ans;
    return dp[n];
}

//Bottom approach:

int minCoinsBU(int n,int coins[],int t){
    int dp[1000]={0};

    //Iterate over all states:
    for(int p=1;p<=n;p++){
        dp[p]=INT_MAX;
        for(int i=0;i<t;i++){
            if((p-coins[i])>=0){
                int sp = dp[p-coins[i]];
                dp[p]=min(dp[p],sp+1);
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int coins[]={1,7,10};
    int dp[1000]={0};
    int t=sizeof(coins)/sizeof(int);

    cout<<minCoins(n,coins,t,dp)<<endl;
    cout<<minCoinsBU(n,coins,t)<<endl;

    return 0;
}

