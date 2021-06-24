#include<iostream>
#include<climits>
using namespace std;
int min_cost_1(int m_start,int m_end,int n_start,int n_end,int **arr){
    if(m_start==m_end-1 && n_start==n_end-1){
        return arr[m_start][n_start];
    }
    if(m_start >= m_end || n_start >= n_end){
        return INT_MAX;
    }
    int x=min_cost_1(m_start,m_end,n_start+1,n_end,arr);
    int y=min_cost_1(m_start+1,m_end,n_start,n_end,arr);
    int z= min_cost_1(m_start+1,m_end,n_start+1,n_end,arr);
    int ans=min(x,min(y,z))+arr[m_start][n_start];
    return ans;
}
// using memoization 
int min_cost_helper(int m_start,int m_end,int n_start,int n_end,int **arr,int **output){
    if(m_start==m_end-1 && n_start== n_end-1){
        return arr[m_start][n_start];
    }
    if(m_start >= m_end && n_start >= n_end){
        return INT_MAX;
    }
    if(output[m_start][n_start]!=-1){
        return output[m_start][n_start];
    }
    int x=min_cost_helper(m_start,m_end,n_start+1,n_end,arr,output);
    int y=min_cost_helper(m_start+1,m_end,n_start,n_end,arr,output);
    int z=min_cost_helper(m_start+1,m_end,n_start+1,n_end,arr,output);
    output[m_start][n_start]=min(x,min(y,z))+arr[m_start][n_start];
    return output[m_start][n_start];
}
int min_cost_2(int m_start,int m_end,int n_start,int n_end,int**arr){
    int **output=new int*[m_end];
    for(int i=0;i<m_end;i++){
        output[i]=new int [n_end];
        for(int j=0;j<n_end;j++){
            output[i][j]=-1;
        }
    }
    return min_cost_helper(m_start,m_end,n_start,n_end,arr,output);
 /*   for(int i=0;i<m_end;i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;*/
}
// using dynamic programming
int min_cost_3(int **arr, int m,int n){
    int **dp=new int*[m];
    for(int i=0;i<m;i++){
        dp[i]=new int[n];
    }
    dp[m-1][n-1]=arr[m-1][n-1];
    // for last col there is no dependancy
    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=dp[i+1][n-1]+arr[i][n-1];
    }
    // for last row there is no dependancy
    for(int j=n-2;j>=0;j--){
        dp[m-1][j]=arr[m-1][j]+dp[m-1][j+1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=arr[i][j]+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
        }
    }
    return dp[0][0];
}
int main(){
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
 //   cout<<min_cost_1(0,m,0,n,arr)<<endl;
 //   cout<<min_cost_2(0,m,0,n,arr)<<endl;
     cout<<min_cost_3(arr,m,n)<<endl;

    //deleting the dynamic array
/*
    for (int i = 0; i < m; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
   */ 
}