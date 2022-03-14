// https://leetcode.com/problems/target-sum/

// for solution refer OneNote
// same code as 8th problem
// i.e. Count subsets with given diff (sum)

#include<bits/stdc++.h>
#define inc_i(x,n) for(int i=x; i < n; i++)
#define inc_j(x,n) for(int j=x; j < n; j++)

using namespace std;

int dp[105][1005];

int countSubsetsWithGivenSum(int arr[],int sum,int n){

    // If sum is 0, then answer is true
    inc_i(0,n+1)
        dp[i][0] = 1;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    inc_i(1,sum+1)
        dp[0][i] = 0;

    inc_i(1,n+1){
        inc_j(1,sum+1){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;

    int x,arr[n],diff,sum=0;
    inc_i(0,n){
        cin>>x;
        arr[i]=x;
        sum+=x;
    }
    cin>>diff;

    int s1 = (sum+diff)/2;

    int ans = countSubsetsWithGivenSum(arr,s1,n);
    cout<<"No. of possible expressions whose sum is same as "<<diff<<" are: "<<ans;

    return 0;
}