#include<bits/stdc++.h>
using namespace std;

 int longestValidParentheses(string s) {
    
   int l =0,r =0,maxLen =0;
   
   for(int i=0;i<s.size();i++){
       if(s[i]=='('){
           l++;
       }
       else{
           r++;
       }
       
       if(l==r){
           maxLen = max(maxLen,2*r);
       }
       else if(r>=l){
           l=0;
           r =0;
       }
   }
   l =0;
   r =0;
   for(int i=s.size()-1;i>=0;i--){
       if(s[i]=='('){
           l++;
       }
       else{
           r++;
       }
       if(l==r){
           maxLen = max(maxLen,2*l);
       }
       else if(l>=r){
           r =0;
           l =0;
       }
   }
   return maxLen;
}

int main(){
    
    string s = "(()";
    cout<<longestValidParentheses(s);
    return 0;
}