// given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

#include<iostream>
#define inc(x,n) for(int i=x; i < n; i++)

using namespace std;

int knapsack(int wt[],int val[],int w,int n){
    // base condition
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]<=w){
        return max((val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),
        knapsack(wt,val,w,n-1));
    }
    else
        return knapsack(wt,val,w,n-1);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    // cout<<"Enter no. of items: \n";
    cin>>n;

    int x,wt[n],val[n],w;

    inc(0,n){
        cin>>x;
        wt[i]=x;
    }
    inc(0,n){
        cin>>x;
        val[i]=x;
    }
    cin>>w;

    int ans = knapsack(wt,val,w,n);
    cout<<"Max. profit = "<<ans;

    return 0;
}