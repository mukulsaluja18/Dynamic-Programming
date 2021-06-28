#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<string,int> my_map;
int helper(string s,int i,int j,bool istrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(istrue==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<j;k=k+2){
        int lt=helper(s,i,k-1,true);
        int lf=helper(s,i,k-1,false);
        int rt=helper(s,k+1,j,true);
        int rf=helper(s,k+1,j,false);
        if(s[k]=='&'){
            if(istrue){
                ans+=lt*rt;
            }
            else{
                ans+=lf*rf+lf*rt+lt*rf;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans+=lt*rf+lt*rt+lf*rt;
            }
            else{
                ans+=lf*rf;
            }
        }
        else{
            if(istrue){
                ans+=lf*rt+lt*rf;
            }
            else{
                ans+=lf*rf+lt*rt;
            }
        }
    }
    return ans;

}
int boolean_rec(string s){
    return helper(s,0,s.size()-1,true);
}
// memoized version
int helper_mem(string s,int i,int j,bool istrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(istrue==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    if(my_map.find(temp)!=my_map.end()){
        return my_map[temp];
    }
    int ans=0;
    for(int k=i+1;k<j;k=k+2){
        int lt=helper(s,i,k-1,true);
        int lf=helper(s,i,k-1,false);
        int rt=helper(s,k+1,j,true);
        int rf=helper(s,k+1,j,false);
        if(s[k]=='&'){
            if(istrue){
                ans+=lt*rt;
            }
            else{
                ans+=lf*rf+lf*rt+lt*rf;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans+=lt*rf+lt*rt+lf*rt;
            }
            else{
                ans+=lf*rf;
            }
        }
        else{
            if(istrue){
                ans+=lf*rt+lt*rf;
            }
            else{
                ans+=lf*rf+lt*rt;
            }
        }
    }
    my_map[temp]= ans;
    return my_map[temp];
}
int boolean_mem(string s){
    return helper_mem(s,0,s.size()-1,true);
}
// solving the qustion using 3d array insted of unordered map
// we can also take vector or array
int main(){
    string s;
    cin>>s;
    //cout<<boolean_rec(s)<<endl;
   // my_map.clear();
   // cout<<boolean_mem(s)<<endl;
    return 0;
}