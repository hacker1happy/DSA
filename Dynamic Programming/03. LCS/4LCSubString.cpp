// Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
// For example, if the given strings are “GEeksforGeeks” and “GeeksQuiz”,
// the output should be 5 as “Geeks” is the longest common substring.


#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[100][100];

int lcs(string x, string y, int m, int n){
    int res = 0;
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                res = max(res,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    return res;
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
    
    cout<<"Length of longest common sub-string [LCS] = "<<ans;

    return 0;
}