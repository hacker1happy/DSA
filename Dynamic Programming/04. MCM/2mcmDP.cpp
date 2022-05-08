// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
// We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 

// (ABC)D = (AB)(CD) = A(BCD) = ....


#include<bits/stdc++.h>
#define loopi(x,n) for(int i=x; i < n; i++)
#define loopk(x,n) for(int k=x; k < n; k++)

using namespace std;

int dp[100][100];

int mcmDP(int a[], int i, int j){
    if(i>=j)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int mn=INT_MAX,cost=0;
    loopk(i,j){
        cost = a[i-1]*a[k]*a[j];
        int temp = cost+mcmDP(a,i,k)+mcmDP(a,k+1,j);
        if(temp<mn) mn=temp;
    }
    dp[i][j]=mn;
    return mn;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    int arr[n];
    loopi(0,n) cin >> arr[i];

    cout<<"Minimum number of multiplications is (using DP) = "<<mcmDP(arr,1,n-1)<<endl;
    return 0;
}