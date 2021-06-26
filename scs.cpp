// smallest common supersequnce
#include<iostream>
#include<string>
using namespace std;
int lcs(string x,string y){
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(x[m-i]==y[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int scs(string x,string y){
    int m=x.size();
    int n=y.size();
    int ans=m+n-lcs(x,y);
    return ans;
}
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    cout<<scs(x,y)<<endl;
    return 0;
}