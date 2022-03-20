// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int change(int a, vector<int>& coins) {
    int n=coins.size();
    int dp[n+1][a+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int j=1;j<=a;j++){
        dp[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a;j++){
            if(coins[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][a];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    // cout<<"Enter no. of items: \n";
    cin>>n;
    vector<int> coins;
    int x,amount;

    inc(0,n){
        cin>>x;
        coins.push_back(x);
    }

    cin>>amount;

    int ans = change(amount,coins);
    
    cout<<"Max. no. of ways [Coin change I] = "<<ans;

    return 0;
}
