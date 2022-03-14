// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


#include<bits/stdc++.h>
#define inc_i(x,n) for(int i=x; i < n; i++)
#define inc_j(x,n) for(int j=x; j < n; j++)

using namespace std;

bool dp[105][1005];

bool subsetSum(int arr[],int sum,int n){

    // If sum is 0, then answer is true
    inc_i(0,n+1)
        dp[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    inc_i(1,sum+1)
        dp[0][i] = false;

    inc_i(1,n+1){
        inc_j(1,sum+1){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
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

    memset(dp,false,sizeof(dp));

    int n;
    cin>>n;

    int x,arr[n],sum;
    inc_i(0,n){
        cin>>x;
        arr[i]=x;
    }
    cin>>sum;

    bool ans = subsetSum(arr,sum,n);
    if(ans){
        cout<<"Sum present";
    } else{
        cout<<"Sum not present";
    }

    return 0;
}