#include<bits/stdc++.h>
using namespace std;

int mySqrt(int A){

    long long ans,i=1;

    while(i*i<=A){
        i++;
    }
    ans =i-1;
    return ans;
}

int main(){
    
    cout<<mySqrt(8);
    return 0;
}