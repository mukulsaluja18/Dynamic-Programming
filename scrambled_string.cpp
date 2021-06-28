#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>my_map;
bool isScrambled(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.size()<=1){
        return false;
    }
    int n=a.size();
    bool flag=false;
    for(int i=1;i<n;i++){
        if(isScrambled(a.substr(0,i),b.substr(0,i))&& isScrambled(a.substr(i,n-i),b.substr(i,n-i))){
            flag=true;
            break;
        }
        if(isScrambled(a.substr(0,i),b.substr(i,n-i))&&isScrambled(a.substr(i,n-i),b.substr(0,n-i))){
            flag=true;
            break;
        }
    }
    return flag;
}
// memoized version
//lly we can do this using map
bool isScrambled_mem(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.size()<=1){
        return false;
    }
    string temp=a;
    temp.push_back('_');
    temp.append(b);
    if(my_map.find(temp)!=my_map.end()){
        return my_map[temp];
    } 
    int n=a.size();
    bool flag=false;
    for(int i=1;i<n;i++){
        if(isScrambled_mem(a.substr(0,i),b.substr(0,i))&& isScrambled_mem(a.substr(i,n-i),b.substr(i,n-i))){
            flag=true;
            break;
        }
        if(isScrambled_mem(a.substr(0,i),b.substr(i,n-i))&&isScrambled_mem(a.substr(i,n-i),b.substr(0,n-i))){
            flag=true;
            break;
        }
    } 
    my_map[temp]=flag;
    return my_map[temp];

}
int main(){
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        return false;
    }
    if(a.size()==0){
        return false;
    }
    cout<<isScrambled_mem(a,b)<<endl;
}