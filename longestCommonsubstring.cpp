#include<iostream>
#include<string>
using namespace std;
int lcs(string x,string y){
    int m=x.size();
    int n=y.size();
    if(m==0||n==0){
        return 0;
    }
    if(x[0]==y[0]){
        return 1+lcs(x.substr(1),y.substr(1));
    }
    else{
        return 0;
    }
}
// memoization
int lcs_helper(string x,string y,int **output){
    int m=x.size();
    int n=y.size();
    if(m==0||n==0){
        return 0;
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    if(x[0]==y[0]){
        output[m][n]=1+lcs_helper(x.substr(1),y.substr(1),output);
    }
    else{
        output[m][n]=0;
    }
    return output[m][n];
}
int lcs_2(string x,string y){
    int m=x.size();
    int n=y.size();
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];
        for(int j=0;j<n+1;j++){
            output[i][j]=-1;
        }
    }
    int ans=lcs_helper(x,y,output);
    for(int i=0;i<m+1;i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;
}
// dp approach
int lcs_3(string x,string y){
    int m=x.size();
    int n=y.size();
    int res=0;
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[m-i]==y[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
            res=max(res,dp[i][j]);
        }
    }
    return res;
}
int main(){
    string x,y;
    cin>>x;
    cin>>y;

 //   cout<<lcs(x,y)<<endl;
 //   cout<<lcs_2(x,y)<<endl;
     cout<<lcs_3(x,y)<<endl;
    return 0;
}