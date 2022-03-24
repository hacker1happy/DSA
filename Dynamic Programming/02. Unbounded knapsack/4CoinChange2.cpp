// Given a list of coins of distinct denominations and total amount of money. Find the minimum number of coins required to make up that amount. Output -1 if that money cannot be made up using given coins.
// You may assume that there are infinite numbers of coins of each type.

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;
int inf = INT_MAX - 1;

int change(int a, vector<int>& coins) {
    int n=coins.size();
    int dp[n+1][a+1];
    
    inc(0,a+1){
        dp[0][i] = inf;
    }
    inc(1,n+1){
        dp[i][0] = 0;
    }

    inc(1,a+1){
        if(i%coins[0]==0)
            dp[1][i] = i/coins[0];
        else
            dp[1][i] = inf;
    }

    inc(2,n+1){
        for(int j=1;j<=a;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            } else{
                dp[i][j] = dp[i-1][j];
            }
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
    cin>>n;
    vector<int> coins;
    int x,sum;

    inc(0,n){
        cin>>x;
        coins.push_back(x);
    }

    cin>>sum;

    int ans = change(sum,coins);

    if(ans == inf)
        cout<<"IMPOSSIBLE";
    else
        cout<<"Minimum no. of coins req. [Coin change II] = "<<ans;

    return 0;
}
