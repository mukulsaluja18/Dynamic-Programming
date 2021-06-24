#include<iostream>
#include<cmath>
#define mod 1000000007
using namespace std;
//u may wonder why we do n-1 or n-2 because in bst the differnece of left sub tree with right can be 0 ,1,-1 thats why
int count_bst_1(int n){
    if(n==0||n==1){
        return 1;
    }
    int x= count_bst_1(n-1);
    int y=count_bst_1(n-2);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans= ((temp1)+(temp2))%mod;
    return ans;
}
// using memoization on the code
int count_bst_helper(int n,int *ans){
    if(n==0||n==1){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a= count_bst_helper(n-1,ans);
    int b=count_bst_helper(n-2,ans);
    int my=((2*a*b)+(a*a));
    ans[n]=my;
    return ans[n];
}
int count_bst_2(int n){
    int* ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return count_bst_helper(n,ans);
}
// using dynamic programming
int count_bst_3(int n){
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=((2*dp[i-1]*dp[i-2]) + (dp[i-1]*dp[i-1]));
    }
    return dp[n];
}
int main(){
    cout<<count_bst_1(4)<<endl;
    cout<<count_bst_2(4)<<endl;
    cout<<count_bst_3(4)<<endl;
}