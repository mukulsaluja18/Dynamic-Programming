// min no of insertion and deltion need to convert sting a to string b
#include<bits/stdc++.h>
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
void min_id(string a,string b){
    int m=a.size();
    int n=b.size();
    int lcs_ans=lcs(a,b);
    int insertion_needed=m-lcs_ans;
    int deletetion_needed=n-lcs_ans;

    cout<<insertion_needed<<" "<<deletetion_needed<<endl;
}
int main(){
    string a,b;
    cin>>a;
    cin>>b;

    min_id(a,b);
    return 0;
}