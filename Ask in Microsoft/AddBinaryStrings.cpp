#include<bits/stdc++.h>
using namespace std;

string addBinary(string A,string B){
    int i = A.size()-1,j = B.size()-1;
    int carry = 0;

    string ans ="";

    while(i>=0 || j>=0 || carry!=0){

        if(i>=0){
            carry+=A[i]=='0'?0:1;
            i--;
        }
        if(j>=0){
            carry+=B[j]=='0'?0:1;
            j--;
        }
        ans =((carry%2)==0?"0":"1") + ans;
        carry/=2;
    }
    return ans;
}

int main(){

    string A = "11",B = "1";
    cout<<addBinary(A,B); 
    return 0;
}