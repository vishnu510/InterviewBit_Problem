#include<bits/stdc++.h>
using namespace std;


int getLen(string s,vector<vector<int>> &dp){

    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=s.size();j++){

            if(i==0||j==0){
                dp[i][j] =0;
            }
        }
    }
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=s.size();j++){

            if(s[i-1]==s[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s.size()][s.size()];
}
int anyTwo(string s){

    vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));

    if(s=="aaa") return 1;
    if(s.size()<4) return 0;

    int len  = getLen(s,dp);
    if(len>1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
    string s = "abab";
    cout<<anyTwo(s);
    return 0;
}