// Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

// Note: The order of characters should be maintained. 

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int dp[100][100];

int lcs(string x, string y, int m, int n){
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1])
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
    string rev = string(x.rbegin(),x.rend());

    int ans = lcs(x,rev,x.length(),x.length());
    
    cout<<"Minimum no, of deletions = "<<(x.length()-ans);

    return 0;
}
