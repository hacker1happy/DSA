// Given an integer W, arrays val[] and wt[], where val[i] and wt[i] are the values and weights of the ith item, the task is to calculate the maximum value that can be obtained using weights not exceeding W.
// Note: Each weight can be included multiple times.

// constraints n<100 && w<1000

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[105][1005];

int knapsack(int wt[],int val[],int w,int n){

    inc(0,n+1){
        for(int j=0;j<=w;j++){
            // base condition
            if(i==0 || j==0)
                dp[i][j]=0;
            
            // n-->i
            // w-->j
            else if(wt[i-1]<=j){
                dp[i][j] = max((val[i-1] + dp[i][j-wt[i-1]]), dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    int n;
    // cout<<"Enter no. of items: \n";
    cin>>n;

    int x,wt[n],val[n],w;

    inc(0,n){
        cin>>x;
        wt[i]=x;
    }
    inc(0,n){
        cin>>x;
        val[i]=x;
    }
    cin>>w;

    int ans = knapsack(wt,val,w,n);
    // Tabulation is called  bottom-up, because we start the solution from base case (initialize matrix using base case) and build the solution to the top (t[n][w] in this case).
    cout<<"Max. profit by unbounded knapsack = "<<ans;

    return 0;
}