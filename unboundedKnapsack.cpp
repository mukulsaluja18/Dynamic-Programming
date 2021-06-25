#include<iostream>
using namespace std;
void take_input(int *arr,int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}
int Unknapsack(int *wt,int *val,int W,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[W+1];
    }
    // initilizations
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }

    // main
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
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
    int *wt=new int [n];
    int *val=new int[n];
    take_input(wt,n);
    take_input(val,n);
    cin>>W;

    cout<<Unknapsack(wt,val,W,n)<<endl;
    return 0;

}