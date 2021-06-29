#include<bits/stdc++.h>
using namespace std;
int goldProfit(int n,int m,int** arr){
    int dp[n][m];
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            // last col
            if(j==m-1){
                dp[i][j]=arr[i][j];
            }
            // first row
            else if(i==0){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            //last row
            else if(i==n-1){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }
            else{
            dp[i][j]=arr[i][j]+max(dp[i+1][j+1],max(dp[i][j+1],dp[i-1][j+1]));
            }
        }
    }
    int my_ans=dp[0][0];
    for(int i=1;i<n;i++){
        if(dp[i][0]>my_ans){
            my_ans=dp[i][0];
        }
    }
    return my_ans;
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int **mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<goldProfit(n,m,mat)<<endl;
    return 0;
}