#include<iostream>
#include<climits>
using namespace std;
int min_step_1(int n){
    if(n<=1){
        return 0;
    }
    if(n==2||n==3){
        return 1;
    }
    int a=min_step_1(n-1);
    int b=INT_MAX,c=INT_MAX;
    if(n%2==0){
        b=min_step_1(n/2);
    }
    if(n%3==0){
        c=min_step_1(n/3);
    }
    return min(a,min(b,c))+1;
}
// doing memoization on the above code
int min_helper(int n,int *ans){
    if(n<=1){
        return 0;
    }
    if(n==2||n==3){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=min_helper(n-1,ans);
    int b=INT_MAX,c=INT_MAX;
    if(n%2==0){
        b=min_helper(n/2,ans);
    }
    if(n%3==0){
        c=min_helper(n/3,ans);
    }
    ans[n]=min(a,min(b,c))+1;
    return ans[n];
}
int min_step_2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return min_helper(n,ans);
}
// using bottom-up approach or we can simply say that using dynamic programming
int min_step_3(int n){
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=n;i++){
        int a=dp[i-1];
        int b=INT_MAX,c=INT_MAX;
        if(i%2==0){
            b=dp[i/2];
        }
        if(i%3==0){
            c=dp[i/3];
        }
        dp[i]=min(a,min(b,c))+1;
    }
    return dp[n];
}

int main(){
    cout<<min_step_1(10)<<endl;
    cout<<min_step_2(10)<<endl;
    cout<<min_step_3(10)<<endl;
}