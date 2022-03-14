// Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
// If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.


#include<bits/stdc++.h>
#define inc_i(x,n) for(int i=x; i < n; i++)
#define inc_j(x,n) for(int j=x; j < n; j++)

using namespace std;

bool dp[105][1005];

bool subsetSum(int arr[],int n,int s){
    // if sum = 0 return ture 
    inc_i(0,n+1){
        dp[i][0] = true;
    }
    // if sum>1 and arr_size==0 then return false
    inc_i(1,s+1){
        dp[0][i] = false;
    }

    // check all other subsets
    inc_i(1,n+1){
        inc_j(1,s+1){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][s];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,false,sizeof(dp));
    int n;
    cin>>n;

    int x,arr[n],range=0;

    inc_i(0,n){
        cin>>x;
        arr[i]=x;
        range+=x;
    }
    bool ans = subsetSum(arr,range,n);
    int s1=0;
    for(int i=range/2;i>=0;i--){
        if(dp[n][i]==true){
            // col represents sum
            // max value of s1
            // so s2 = range - s1 and (range -2*s1) will be min
            s1=i;
            break;
        }
    }
    cout<<"Min. subset difference is: "<<(range - 2*s1);
    return 0;
}