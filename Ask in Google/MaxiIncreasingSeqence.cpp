#include<bits/stdc++.h>
using namespace std;



int dp[200][200];
int n,m,cn;
int solve(vector<vector<int>>& A,int i,int j,int prev){

    if(i<0 || j<0 || i>=n || j>=m || A[i][j]<=prev) return 0;

    if(dp[i][j]) return dp[i][j];

    return dp[i][j] = 1 + max({solve(A,i-1,j,A[i][j]),
                            solve(A,i+1,j,A[i][j]),
                            solve(A,i,j-1,A[i][j]),
                            solve(A,i,j+1,A[i][j])});
}
int longestIncreasingPath(vector<vector<int>>& A){

    n = A.size();
    m = A[0].size();
    cn =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cn = max(cn,solve(A,i,j,-1));
        }
    }
    return cn;
}



int main(){
    
    vector<vector<int>> A = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(A);
    return 0;
}