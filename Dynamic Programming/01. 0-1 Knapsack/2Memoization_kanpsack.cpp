// given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

// constraints n<100 && w<1000

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[105][1005];

int knapsack(int wt[],int val[],int w,int n){
    //base condition
    if(n==0 || w==0) 
        return 0;
    
    // if ans already present in the dp
    // then value at dp != -1
    if(dp[n][w]!=-1)
        return dp[n][w];

    // choice 1.
    // if curr_weight < available_weight
    // the either consider its weight or not
    // and take its max.
    if(wt[n-1]<=w){
       dp[n][w] = max((val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));
    }

    // choice 2.
    // if curr_weight > available_weight
    // the don't consider that weight 
    else if(wt[n-1]>w)
        dp[n][w] = knapsack(wt,val,w,n-1);

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
    // memoization is a top-down apporach
    // as the solution starts from the given value in the ques.
    // we divide the problem into smaller sub-problems
    cout<<"Max. profit in memoization(top-down) = "<<ans;

    return 0;
}