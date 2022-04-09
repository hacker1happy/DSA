// Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.

#include<bits/stdc++.h>
#define inc(x,n) for(int i=x; i < n; i++)
#define jnc(x,n) for(int j=x; j < n; j++)

using namespace std;

int dp[100][100];

int lcs(string a, string b, int n, int m){
    inc(0,n+1){
        dp[0][i]=0;
    }
    inc(0,m+1){
        dp[i][0]=0;
    }

    inc(1,n+1){
        jnc(1,m+1){
            if(dp[i][j]!=-1)
                return dp[i][j];
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
    }
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

    int l = lcs(x,y,x.length(),y.length());
    
    cout<<"Length of shortest common super-sequence = "<<(x.length()+y.length()-l);

    return 0;
}