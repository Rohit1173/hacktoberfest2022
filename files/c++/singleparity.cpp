#include<iostream>
using namespace std;
string addbit(string s){
int x=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            x++;
        }
    }
    if(x%2==0){
        s=s+"0";
    }
    else{
        s=s+"1";
    }
    return s;
}
int main(){
    string s= "101101001001";
    string s1=addbit(s);
    cout<<s1<<endl;
}