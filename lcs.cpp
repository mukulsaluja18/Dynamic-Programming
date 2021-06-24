#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;
// using recursion
int lcs_1(string s,string t){
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+lcs_1(s.substr(1),t.substr(1));
    }
    else{
        int a=lcs_1(s.substr(1),t);
        int b=lcs_1(s,t.substr(1));
        int c= lcs_1(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}
// applying memoization 
int lcs_helper(string s,string t,int **output){
    int m=s.size();
    int n=t.size();
    if(m==0 || n==0){
        return 0;
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    //recusrive calls
    if(s[0]==t[0]){
         ans= 1+lcs_helper(s.substr(1),t.substr(1),output);
    }
    else{
         ans= max(lcs_helper(s.substr(1),t,output),lcs_helper(s,t.substr(1),output));
    }
    output[m][n]=ans;
    return ans;
}
int lcs_2(string s,string t){
    int **output=new int*[s.size()+1];
    for(int i=0;i<=s.size();i++){
        output[i]=new int[t.size()+1];
        for(int j=0;j<=t.size();j++){
            output[i][j]=-1;
        }
    }
    int ans=lcs_helper(s,t,output);
    for(int i=0;i<=s.size();i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;
}
// using dynamic programming approach
int lcs_3(string s,string t){
    int m=s.size();
    int n=t.size();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    // initilizations
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=n;j++){
        dp[0][j]=0;
    }
    // main logic
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){ // we do m-i not i bcoz we need last characters matching 
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}
int main(){
    string  s,t;
    cin>>s;
    cin>>t;

    //using recusrion 
 //   cout<<lcs_1(s,t)<<endl;
 //    cout<<lcs_2(s,t)<<endl;
     cout<<lcs_3(s,t)<<endl;
    return 0;
}