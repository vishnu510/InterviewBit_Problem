#include<bits/stdc++.h>
using namespace std;

bool isDigit(char c){

    return c >='0' && c<='9'; 
}

int Atoi(string A){

    int len = A.size();
    if(len==0) return 0;

    int idx =0;
    while(idx<len && A[idx]==' '){
        ++idx;
    }
    if(idx==len) return 0;
    char ch;

    bool isNegative = (ch=A[idx])=='-';

    if(isNegative || A[idx]=='+'){
        ++idx;
    }

    int maxLim  = INT_MAX/10;
    int res =0;
    while(idx <len && isDigit(ch=A[idx])){

        int digit = ch-'0';
        if(res> maxLim ||(res==maxLim &&digit >7)){
            return isNegative ? INT_MIN:INT_MAX;
        }

        res = (res*10) + digit;
        ++idx;
    }
    return isNegative?-res:res;
}
int main(){

    string A = "9 2704";
    cout<<Atoi(A);
    return 0;
}