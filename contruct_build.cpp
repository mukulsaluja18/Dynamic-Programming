#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll CountWays(int n){
    ll obuilding=1;
    ll ospace=1;
    for(int i=2;i<=n;i++){
        ll nbuilding=ospace;
        ll nspace=obuilding+ospace;

        ospace=nspace;
        obuilding=nbuilding;
    }
    ll ans=(obuilding+ospace);
    return (ans*ans);
}
int main(){
    int n;
    cin>>n;
    cout<<CountWays(n)<<endl;
    return 0;
}