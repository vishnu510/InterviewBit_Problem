#include<bits/stdc++.h>
using namespace std;

int strStr(string A,string B){
    int len1 = A.size(),len2 = B.size();
    
    if(len2==0) return 0;
    
    int j =0;
    for(int i=0;i<len1;i++){
        
        if(A[i]==B[j]){
            j++;
        }
        else{
            
            i = i-j;
            j=0;
        }
        
        if(j==len2){
            return i-j+1;
        }
    }
    return -1;
}

int main(){
    
    string A = "hello", B = "ll";
    cout<<strStr(A,B);
    return 0;
}