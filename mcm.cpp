#include<bits/stdc++.h>
using namespace std;
// recursive solution
int helper(int *arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=helper(arr,i,k)+helper(arr,k+1,j)+(arr[i]*arr[k]*arr[j]);
        if(temp<mn){
            mn=temp;
        }
    }
    return mn;
}
// memoizaed version of mcm
int mem_helper(int* arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp_ans=mem_helper(arr,i,k,dp)+mem_helper(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
        if(temp_ans<mn){
            mn=temp_ans;
        }
    }
    dp[i][j]=mn;
    return dp[i][j];
}
int matrixMultiplication(int N, int arr[]){   
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
       /* for(int i=0;i<=N;i++){
            dp[i][i]=0;
        }*/
        return mem_helper(arr,1,N-1,dp);
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return 0;
}