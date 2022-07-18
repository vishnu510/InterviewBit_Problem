#include<bits/stdc++.h>
using namespace std;

int isMatch(const string A, const string B){

    int n = A.size(),m=B.size();

    int dp[n+1][m+1];
    dp[0][0] =true; // when string and pattern both are empty;

    if(m) dp[0][1] = false; // if only patter not string

    for(int i=1;i<=n;i++){
        dp[i][0]  = false; // if only string not pattern 
    }

    for(int j=2;j<=m;j++){

        if(B[j-1]=='*'){
            dp[0][j] = dp[0][j-2];
        }
        else{
            dp[0][j] = false;
        }
    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(B[j-1]=='.' || A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{

                if(B[j-1]=='*' && j>1){
                    if(B[j-2]==A[i-1] || B[j-2]=='.'){
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[n][m];
}

int main(){

    string s= "aa",p= "a*";
    cout<<isMatch(s,p);
    return 0;
}