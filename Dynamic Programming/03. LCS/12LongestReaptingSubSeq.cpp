// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
// Problem link: "https://www.geeksforgeeks.org/longest-repeated-subsequence/"

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[100][100];

int lcs(string x, string y, int m, int n){
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1] && i!=j)
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    return dp[m][n];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));

    string x;
    cin>>x;
    int m = x.length();
    int ans = lcs(x,x,m,m);
    
    cout<<"Longest repeating sub-sequence [LRS] = "<<ans;
    
    return 0;
}
