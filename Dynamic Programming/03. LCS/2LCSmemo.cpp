// LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 


#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[100][100];

int lcs(string x, string y, int m, int n){
    if(n==0||m==0)
        dp[n][m] = 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(x[m-1]==y[n-1])
        dp[n][m] = 1+lcs(x,y,m-1,n-1);
    else
        dp[n][m] = max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
    return dp[n][m];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    memset(dp,-1,sizeof(dp));

    string x,y;
    cin>>x>>y;

    int ans = lcs(x,y,x.length(),y.length());
    
    cout<<"Length of longest common sub-sequence [LCS] = "<<ans;

    return 0;
}