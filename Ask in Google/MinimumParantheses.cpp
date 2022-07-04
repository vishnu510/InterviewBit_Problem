#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s){
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stk.push('(');
        }
        else{
            if(!stk.empty() && stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(')');
            }
        }
    }
    return stk.size();
}

int main(){
     
    string str ="())";
    cout<<minAddToMakeValid(str);
    return 0;
}