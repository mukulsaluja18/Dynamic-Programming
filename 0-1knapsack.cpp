#include<iostream>
using namespace std;
void take_input(int *arr,int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}
int knapsack_1(int* wt,int* val,int W,int n){
    // Base case
    if(n==0||W==0){
        return 0;
    }
    // recusrive calls
    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack_1(wt,val,W-wt[n-1],n-1),knapsack_1(wt,val,W,n-1));
    }
    else{
        return knapsack_1(wt,val,W,n-1);
    }
}
// using memoization 
int knapsack_helper(int *wt,int *val,int W,int n,int **output){
    if(n==0||W==0){
        return 0;
    }
    if(output[n][W]!=-1){
        return output[n][W];
    }
    if(wt[n-1]<=W){
        output[n][W]=max(val[n-1]+knapsack_helper(wt,val,W-wt[n-1],n-1,output),knapsack_helper(wt,val,W,n-1,output));
    }
    else{
        output[n][W]=knapsack_helper(wt,val,W,n-1,output);
 
    }
    return output[n][W];
}
int knapsack_2(int *wt,int *val,int W,int n){
    int** output=new int *[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=new int[W+1];
        for(int j=0;j<W+1;j++){
            output[i][j]=-1;
        }
    }
    int ans=knapsack_helper(wt,val,W,n,output);
    for(int i=0;i<n+1;i++){
        delete []  output[i];
    }
    delete []  output;
    return ans;
}
// using Dynamic programming approach
int knapsack_3(int *wt,int * val,int W,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=new int[W+1];
    }
    // initilization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    // main calls
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n,W;
    cin>>n;
    int *wt=new int[n];
    int *val=new int[n];
    take_input(wt,n);
    take_input(val,n);
    cin>>W;

//    cout<<knapsack_1(wt,val,W,n)<<endl;
//    cout<<knapsack_2(wt,val,W,n)<<endl;
      cout<<knapsack_3(wt,val,W,n)<<endl;
    return 0;

}