#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int lcs(string x,string y){
    int m=x.size();
    int n=y.size();
    int res=0;
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
                dp[i][j]=0;
        
            }
            res=max(res,dp[i][j]);
        }
    }
    return res;
}
int lps(string x){
    string y=x;
    reverse(y.begin(),y.end());
    int ans=lcs(x,y);
    return ans;
}
int main(){
    string x;
    cin>>x;
    cout<<lps(x)<<endl;
    return 0;
}