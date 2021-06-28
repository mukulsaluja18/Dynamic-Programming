#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int i,int j){
    if(i==j){
        return true;
    }
    while(j>i){
        if (s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}
int palindrome_rec(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans=1+palindrome_rec(s,i,k)+palindrome_rec(s,k+1,j);
        if(temp_ans<mn){
            mn=temp_ans;
        }
    }
    return mn;
}
// memoized
int mem_helper(string s,int i,int j,vector<vector<int>>& dp){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans=1+mem_helper(s,i,k,dp)+mem_helper(s,k+1,j,dp);
        if(temp_ans<mn){
            mn=temp_ans;
        }
    }
    dp[i][j]=mn;
    return dp[i][j];
}
int helper_opt(string s,int i,int j,vector<vector<int>>& dp){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int left,right;
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }
        else{
            left=helper_opt(s,i,k,dp);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1){
            right=dp[k+1][j];
        }
        else{
            right=helper_opt(s,k+1,j,dp);
            dp[k+1][j]=right;
        }
        int temp_ans=1+left+right;
        if(temp_ans<mn){
            mn=temp_ans;
        }
    }
    dp[i][j]=mn;
    return dp[i][j];
}
int palindrome_mem(string s){
    vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
    return helper_opt(s,0,s.size()-1,dp);
}
int main(){
    string s;
    cin>>s;
   // cout<<palindrome_rec(s,0,s.size()-1)<<endl;
    //cout<<palindrome_mem(s)<<endl;
    cout<<palindrome_mem(s)<<endl;
    return 0;
}
