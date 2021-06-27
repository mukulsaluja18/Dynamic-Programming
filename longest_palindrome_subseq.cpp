#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int lcs(string x,string y){
    int m=x.size();
    int n=y.size();
    int dp[2][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i%2][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i%2][j]=1+dp[(i+1)%2][j-1];
            }
            else{
                dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
            }
        }
    }
    return dp[m%2][n];
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