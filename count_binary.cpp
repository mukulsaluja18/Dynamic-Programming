// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion
#include<bits/stdc++.h>
using namespace std;
// below is of consecutive 0,s not allowed
int count_conce_0_not(int n){
    int ozeros=1;
    int oones=1;
    for(int i=2;i<=n;i++){
        int nzeros=oones;
        int nones=oones+ozeros;

        oones=nones;
        ozeros=nzeros; // we do this bcoz out current ouput for 1 depend on prev 0 and 1 and for 0 it depend on prev 1 output if consecutive 0s not allowed
    }
    return (ozeros+oones);
}
// below is if consecutive 1's not allowed
int count_conce_1_not(int n){
    int ozeros=1;
    int oones=1;
    for(int i=2;i<=n;i++){
        int nzeros=oones+ozeros;
        int nones=ozeros;

        oones=nones;
        ozeros=nzeros;   
    }
    return (ozeros+oones);
}
// for greater inout do mod 10^9+7
int main(){
    int n;
    cin>>n;
    cout<<count_conce_0_not(n)<<endl;
}