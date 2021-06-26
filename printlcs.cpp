#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void print_lcs(string x,string y){
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    //main
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[m-i]==y[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=m,j=n;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
        else{
                i--;
            }
        }
        reverse(s.begin(),s.end());
        cout<<s;
    }
    
    
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    print_lcs(x,y);
    return 0;
}