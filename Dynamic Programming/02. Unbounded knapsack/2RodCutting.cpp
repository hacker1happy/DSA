// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20


#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[105][1005];

int rodCut(int length[],int price[],int l,int n){
    inc(0,n+1){
        for(int j=0;j<=l;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(length[i-1]<=j){
                dp[i][j] = max((price[i-1]+dp[i][j-length[i-1]]), dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[l][n];    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;

    int x,length[n],price[n];

    inc(0,n){
        cin>>x;
        length[i]=x;
    }
    inc(0,n){
        cin>>x;
        price[i]=x;
    }

    int ans = rodCut(length,price,n,n);
    
    cout<<"Max. price in rod cutting = "<<ans;

    return 0;
}