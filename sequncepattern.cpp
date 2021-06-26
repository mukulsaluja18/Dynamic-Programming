#include<bits/stdc++.h>
// in this we have to check if a is a substring of b or not
using namespace std;
int lcs(string s,string t){
    int m=s.size();
    int n=t.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(s[m-i]==t[n-j]){ // we do m-i not i bcoz we need last characters matching 
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
bool sequence_pattern(string a,string b){
    int lcs_ans=lcs(a,b);
    if(lcs_ans==a.size()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string a,b;
    cin>>a;
    cin>>b;

    cout<<sequence_pattern(a,b)<<endl;
}