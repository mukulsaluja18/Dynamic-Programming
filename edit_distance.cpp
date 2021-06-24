#include<iostream>
#include<string>
using namespace std;
int edit_1(string s,string t){
    int m=s.size();
    int n=t.size();
    if(m==0 || n==0){
        return max(m,n);
    }

    if(s[0]==t[0]){
        return edit_1(s.substr(1),t.substr(1));
    }
    else{
        int a=edit_1(s,t.substr(1))+1;
        int b=edit_1(s.substr(1),t)+1;
        int c=edit_1(s.substr(1),t.substr(1))+1;
        return min(a,min(b,c));
    }
}
// using memoization 
int edit_helper(string s,string t,int **output){
    int m=s.size();
    int n=t.size();
    if(m==0||n==0){
        return max(m,n);
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    //cases
    int ans;
    if(s[0]==t[0]){
        ans=edit_helper(s.substr(1),t.substr(1),output);
    }
    else{
        int a=edit_helper(s,t.substr(1),output)+1;
        int b=edit_helper(s.substr(1),t,output)+1;
        int c=edit_helper(s.substr(1),t.substr(1),output)+1;
        ans= min(a,min(b,c));
    }
    output[m][n]=ans;
    return ans;
}
int edit_2(string s,string t){
    int m=s.size();
    int n=t.size();
    int ** output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    int result=edit_helper(s,t,output);
    for(int i=0;i<=m;i++){
        delete [] output[i];
    }
    delete output;
    return result;
}
int edit_3(string s,string t){
    int m=s.size();
    int n=t.size();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    // initilization
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=n;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s ,t;
    cin>>s;
    cin>>t;

    //cout<<edit_1(s,t)<<endl;
//    cout<<edit_2(s,t)<<endl;
    cout<<edit_3(s,t)<<endl;
    return 0;
}