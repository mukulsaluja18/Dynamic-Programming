#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool **SubsetSumhelper(int *arr,int sum,int n){
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

    return dp;
}

int minSub(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    bool **output=SubsetSumhelper(arr,sum,n);
    vector<int> result;
    for(int i=0;i<=sum/2;i++){
        if(output[n][i]){
            result.push_back(i);
        }
    }
    // calculating 
    int mn=INT_MAX;
    for(int i=0;i<result.size();i++){
        mn=min(mn,sum-2*result[i]);
    }
    return mn;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minSub(arr,n)<<endl;
    return 0;
}