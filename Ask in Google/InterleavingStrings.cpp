#include<bits/stdc++.h>
using namespace std;


bool check(string a,string b,string c,int i,int j,int k,vector<vector<int>>& dp){

    if(dp[i][j]!=-1) return dp[i][j];

    if(i==a.size() && j==b.size() && k==c.size()){
        return true;
    }

    bool res = false;

    if(i!=a.size()){
        if(a[i]==c[k]){
            res|=check(a,b,c,i+1,j,k+1,dp);
        }
    }
    if(j!=b.size()){
        if(b[j]==c[k]){
            res|=check(a,b,c,i,j+1,k+1,dp);
        }
    }
    return dp[i][j] = res;
}

int isInterleave(string A, string B, string C){

    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans =  check(A,B,C,0,0,0,dp);
    return ans;
}

int main(){
    

    string A= "aabcc",B= "dbbca",C= "aadbbcbcac";
    cout<<isInterleave(A,B,C);
    return 0;
}