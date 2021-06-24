#include<iostream>
using namespace std;
int staircase_1(int n){
    if(n<=1){
        return 1;
    }
    if(n==2){
        return n;
    }
    return staircase_1(n-1)+staircase_1(n-2)+staircase_1(n-3);
}
// using memoization on the above code
int staircase_helper(int n,int *ans){
    if(n<=1){
        return 1;
    }
    if(n==2){
        return n;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    ans[n]=staircase_helper(n-1,ans)+staircase_helper(n-2,ans)+staircase_helper(n-3,ans);
    return ans[n];
}
int staircase_2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return staircase_helper(n,ans);
}
//using dynamic programming
int staircase_3(int n){
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}
int main(){
    cout<<staircase_1(10)<<endl;
    cout<<staircase_2(10)<<endl;
    cout<<staircase_3(10)<<endl;
}