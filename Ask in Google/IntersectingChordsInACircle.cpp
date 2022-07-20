#include<bits/stdc++.h>
using namespace std;

int cordCount(int A){

    vector<long long int> dp(A+1);
    for(int i=0;i<A+1;i++){
        dp[i] =0;
    }
    int mod = 1e9+7;
    dp[0] =1;
    dp[1] =1;
    dp[2] =2;

    for(int i=3;i<A+1;i++){

        for(int j=0;j<i;j++){
            dp[i] =(dp[i] + dp[i-j-1]*dp[j])%mod;
        }
    }
    return dp[A]%mod;
}

int main(){
    
    int A;
    cin>>A;
    cout<<cordCount(A);
    return 0;
}