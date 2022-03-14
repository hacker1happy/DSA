// Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 


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

    int x,arr[n],sum=0;
    inc_i(0,n){
        cin>>x;
        arr[i]=x;
        sum+=x;
    }
    // if total_sum of the array is odd 
    // it can never be divided into two parts of equal sum
    if(sum%2!=0){
        cout<<"Can not be divided.";
    }
    else{
        bool ans = subsetSum(arr,sum/2,n);
        if(ans){
            cout<<"Can be divided.";
        } else{
            cout<<"Can not be divided.";
        }
    }   

    return 0;
}