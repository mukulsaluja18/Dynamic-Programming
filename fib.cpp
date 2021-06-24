#include<iostream>
using namespace std;
// fib using recursion
int fibo_1(int n){
    if(n<=1){
        return n;
    }
    int a=fibo_1(n-1);
    int b=fibo_1(n-2);
    return a+b;
}
// applying memoization on the above
int fibo_helper(int n,int *ans){
    if(n<=1){
        return n;
    }
    //checking the ans if it exists or not if exists then we do
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);
    ans[n]=a+b;
    return ans[n];
}
int fibo_2(int n){
    int * ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}
// using iterative approach or doing dynamic-programming
int fibo_3(int n){
    int * dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    cout<<fibo_1(6)<<endl;
    cout<<fibo_2(6)<<endl;
    cout<<fibo_3(6)<<endl;
}