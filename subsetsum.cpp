#include<iostream>
using namespace std;
bool subset_sum1(int *arr,int sum,int n){
    // base cases
    if(sum==0 && n==0){
        return true;
    }
    if(n==0 && sum!=0){
        return false;
    }
    if(n!=0 && sum==0){
        return true;
    }
    // recursive calls
    if(arr[n-1]<=sum){
        return subset_sum1(arr,sum-arr[n-1],n-1) || subset_sum1(arr,sum,n-1);
    }
    else{
        return subset_sum1(arr,sum,n-1);
    }
}
// memoization
int subset_helper(int *arr,int sum,int n,int **output){
    if(sum==0 && n==0){
        return true;
    }
    if(n==0 && sum!=0){
        return false;
    }
    if(n!=0 && sum==0){
        return true;
    }
    if(output[n][sum]!=-1){
        return output[n][sum];
    }
    if(arr[n-1]<=sum){
        output[n][sum]= subset_sum1(arr,sum-arr[n-1],n-1) || subset_sum1(arr,sum,n-1);
    }
    else{
        output[n][sum]= subset_sum1(arr,sum,n-1);
    }
    return output[n][sum];

}
bool subset_sum2(int *arr,int sum,int n){
    int **output=new int *[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=new int[sum+1];
        for(int j=0;j<sum+1;j++){
            output[i][j]=-1;
        }
    }
    int ans=subset_helper(arr,sum,n,output);
    for(int i=0;i<n+1;i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;
}
// using dynamic programming
bool subset_sum3(int *arr,int sum,int n){
    bool **dp=new bool*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=new bool[sum+1];
    }
    // initilization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    // main calls

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;

    //cout<<subset_sum1(arr,sum,n)<<endl;
    cout<<subset_sum2(arr,sum,n)<<endl;
 //   cout<<subset_sum3(arr,sum,n)<<endl;
}