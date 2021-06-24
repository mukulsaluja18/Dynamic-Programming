#include<iostream>
#include<climits>
using namespace std;
int min_count_1(int n){
    if(n<=3){
        return n;
    }
    int ans=INT_MAX;
    int i=1;
    while((i*i)<=n){
        int rec=1+min_count_1(n-i*i);
        ans=min(ans,rec);
        i++;
    }
    return ans;
}
//using memoiztion on the above
int min_count_helper(int n,int * ans){
    if(n<=3){
        return n;
    }
    if(ans[n]!=-1){
        return ans[n];
    }

    int my=INT_MAX, i=1;
    while((i*i)<=n){
        int rec_ans=min_count_helper(n-i*i,ans)+1;
        my=min(my,rec_ans);
        i++;
    }
    ans[n]=my;
    return ans[n];
}
int min_count_2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return min_count_helper(n,ans);
}
// using dynamic programming approach
int min_count_3(int n){
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++){
        int j=1,ans=INT_MAX;
        while((j*j)<=i){ // we can also use for loop tpo run from 1 to i/2
            int rec=dp[i-j*j]+1;
            ans=min(rec,ans);
            j++;
        }
        dp[i]=ans;
    }
    return dp[n];
}
int main(){
    cout<<min_count_1(12)<<endl;
    cout<<min_count_2(12)<<endl;
    cout<<min_count_3(12)<<endl;
}