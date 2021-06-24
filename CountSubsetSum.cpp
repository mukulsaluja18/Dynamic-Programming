#include<iostream>
using namespace std;
int count_subset_sum(int *arr,int sum,int n){
    int **output=new int*[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=new int[sum+1];
    }

    // initilization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                output[i][j]=0;
            }
            if(j==0){
                output[i][j]=1;
            }
        }
    }
    // main callls
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                output[i][j]=output[i-1][j-arr[i-1]]+output[i-1][j];
            }
            else{
                output[i][j]=output[i-1][j];
            }
        }
    }
    return output[n][sum];
}
int main(){
    int n,sum;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;
    cout<<count_subset_sum(arr,sum,n)<<endl;
}