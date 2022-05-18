// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
// https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/


#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

bool scrambleString(string a, string b){
    if(a.compare(b)==0)
        return true;
    if(a.length()<1)
        return false;
    string key = a+"_"+b;
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    bool flag;
    for(int i=1;i<a.length();i++){
        flag = false;
        if(scrambleString(a.substr(0,i),b.substr(0,i)) && scrambleString(a.substr(i,a.length()-i),b.substr(i,b.length()-i)))
            flag = true;
        if(scrambleString(a.substr(0,i),b.substr(b.length()-i,i)) && scrambleString(a.substr(i,a.length()-i),b.substr(0,b.length()-i)))
            flag = true;
        if(flag)
            break;
    }
    return mp[key] = flag;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // INPUT string of symbols and operators
    string s1,s2;
    cin>>s1>>s2;
    
    // OUTPUT true or false
    if(s1.length()!=s2.length())
        cout<<"Length of strings are not equal";
    else if(scrambleString(s1,s2))
        cout<<"Scrambled";
    else
        cout<<"Not Scrambled";
    return 0;
}