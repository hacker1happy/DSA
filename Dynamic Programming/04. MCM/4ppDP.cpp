// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.


#include<bits/stdc++.h>
#define loopi(x,n) for(int i=x; i < n; i++)
#define loopk(x,n) for(int k=x; k < n; k++)

using namespace std;

int dp[100][100];

bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}

int ppDP(string s, int i, int j){
    if(i>=j)    return 0;
    if(isPalindrome(s,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mn=INT_MAX;
    loopk(i,j){
        int temp = 1+ppDP(s,i,k)+ppDP(s,k+1,j);
        if(temp<mn) mn=temp;
    }
    return dp[i][j]=mn;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;

    cout<<"Minimum number of partions to be done to get the substrings as a palindrome are(using DP) = "<<ppDP(s,0,s.length()-1)<<endl;
    return 0;
}