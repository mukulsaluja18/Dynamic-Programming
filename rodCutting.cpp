#include<iostream>
// pepcoding video
// there is two stragedy 1-> cut and 2 -> left right
using namespace std;
// using left right 
int cutRod(int *prices,int n){
        int np[n+1];
        for(int i=0;i<n+1;i++){
            np[i+1]=prices[i];
        }
        
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=np[i];
            int li=1;
            int ri=i-1;
            while(li<=ri){
                if(dp[li]+dp[ri]>dp[i]){
                    dp[i]=dp[li]+dp[ri];
                }
                li++;
                ri--;
            }
        }
        return dp[n];
}
// using cut stargedy
 
int main(){
    int n;
    cin>>n;
    int *prices=new int[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<cutRod(prices,n)<<endl;
    return 0;

}