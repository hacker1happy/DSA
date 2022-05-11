/*Given a boolean expression with following symbols. 
Symbols
    'T' ---> true 
    'F' ---> false 

And following operators filled between symbols 
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. */

#include<bits/stdc++.h>
using namespace std;

int eval(string s, int i, int j, bool flag){
    // When string s is empty
    if(i>j)
        return 0;

    // When string s is of length 1
    if(i==j){
        // If flag is true, then return 1 if s[i] is 'T' else return 0
        if(flag)
            return s[i]=='T';
        // If flag is false, then return 0 if s[i] is 'T' else return 1
        else
            return s[i]=='F';
    }

    // k loop scheme
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lT = eval(s,i,k-1,true);
        int lF = eval(s,i,k-1,false);
        int rT = eval(s,k+1,j,true);
        int rF = eval(s,k+1,j,false);

        // Check for the operator is of which type, so that ans can be calculated
        if(s[k]=='&'){
            // required flag is true
            if(flag)
                ans+=(lT*rT);
            else
                ans+=(lF*rF)+(lF*rT)+(lT*rF);
        } else if(s[k]=='|'){
            // required flag is true
            if(flag)
                ans+=(lT*rT)+(lF*rT)+(lT*rF);
            else
                ans+=(lF*rF);
        } else if(s[k]=='^'){
            // required flag is true
            if(flag)
                ans+=(lT*rF)+(lF*rT);
            else
                ans+=(lT*rT)+(lF*rF);
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // INPUT string of symbols and operators
    string s;
    cin>>s;
    
    // OUTPUT number of ways to parenthesize the expression
    cout<<"Number of ways to parenthesize the expression = "<<eval(s,0,s.length()-1,true)<<endl;
    return 0;
}
