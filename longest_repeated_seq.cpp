#include<bits/stdc++.h>
using namespace std;
int longest_repeated(string s){
    int m=s.size();
    string t=s;
    int n=t.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(s[m-i]==t[n-j] && i!=j){ // we do m-i not i bcoz we need last characters matching 
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string a;
    cin>>a;
    cout<<longest_repeated(a)<<endl;
    return 0;
}