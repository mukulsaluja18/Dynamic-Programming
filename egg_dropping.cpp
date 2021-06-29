#include<bits/stdc++.h>
using namespace std;
int egg_Drop_rec(int n,int k){
    if(k==0||k==1||n==1){
        return k;
    }
    int mn=INT_MAX;
    for(int i=1;i<=k;i++){
        int temp=1+max(egg_Drop_rec(n-1,i-1),egg_Drop_rec(n,k-i));
        mn=min(mn,temp);
    }
    return mn;
}
// memoized 
int helper(int n,int k,int** dp){
    if(k==0||k==1){
        return k;
    }
    if(n==1){
        return k;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int mn=INT_MAX;
    for(int j=1;j<=k;j++){
        int low,low_h;
        if(dp[n-1][j-1]!=-1){
            low=dp[n-1][j-1];
        }
        else{
            dp[n-1][j-1]=helper(n-1,j-1,dp);
            low=dp[n-1][j-1];
        }
        if(dp[n][k-j]!=-1){
            low_h=dp[n][k-j];
        }
        else{
            dp[n][k-j]=helper(n,k-j,dp);
            low_h=dp[n][k-j];
        }
        int temp=1+max(low,low_h);
        mn=min(mn,temp);
    }
    dp[n][k]=mn;
    return dp[n][k];
}
int eggDrop(int n, int k) {
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[k+1];
        for(int j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    int ans=helper(n,k,dp);
    return ans;
}
// in memoized version we can use binary serach instead of linear search
int helper_opt(int n,int k){
    if(n==1|k==0||k==1){
        return k;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int low=1;
    int high=k;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int left=helper_opt(n-1,mid-1);
        int right=helper_opt(n,k-mid);
        int temp=1+max(left,right);
        if(left<right){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        ans=min(ans,temp);
    }
    dp[n][k]=ans;
    return dp[n][k];
}
int main(){
    int n,k; // n stands for eggs and k stands for floors
    cin>>n>>k;
    cout<<egg_Drop_rec(n,k);
    return 0;
}