// LCS Problem Statement: Given two sequences, find the longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 


#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[100][100];

string printLCS(string x, string y, int m, int n){
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }

    string s="";
    int i = m, j = n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s=x[i-1]+s;
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    return s;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));

    string x,y;
    cin>>x>>y;

    string ans = printLCS(x,y,x.length(),y.length());
    
    cout<<"longest common sub-sequence = "<<ans;

    return 0;
}