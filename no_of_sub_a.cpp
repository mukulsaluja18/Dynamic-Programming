// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/
#include<bits/stdc++.h>
using namespace std;
    int fun(string str){
        int a=0;
        int ab=0;
        int abc=0;
        for(int i=0;i<str.size();i++){
            char my_char=str[i];
            if(my_char=='a'){
                a=2*a+1;
            }
            else if(my_char=='b'){
                ab=2*ab+a;
            }
            else{
                abc=2*abc+ab;
            }
        }
        return abc;
    }
int main(){
    string str;
    cin>>str;
    cout<<fun(str)<<endl;
}