#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& t){

    stack<int> stk;
    for(int i=0;i<t.size();i++){

        if(t[i]=="+" || t[i]=="-" || t[i]=="*" || t[i]=="/"){
            int y = stk.top();
            stk.pop();
            int x = stk.top();
            stk.pop();
            switch (t[i][0])
            {
            case '+':
                stk.push(x+y);
                break;

            case '-':
                stk.push(x-y);
                break;
            
            case '*':
                stk.push(x*y);
                break;
            
            case '/':
                stk.push(x/y);
                break;
            
        }
        
    }
        else{
            stk.push(stoi(t[i]));
            }
    }    
return stk.top();
}

int main(){

    vector<string> tokens ={"4","13","5","/","+"};
    cout<<evalRPN(tokens);
    return 0;
}