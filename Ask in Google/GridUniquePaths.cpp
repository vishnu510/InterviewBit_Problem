#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){

    vector<vector<int>> res(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                res[i][j] =1;
            }
            else{
                res[i][j] = res[i-1][j]+res[i][j-1];
            }
        }
    }
    return res[m-1][n-1];
}

int main(){

    cout<<uniquePaths(3,7);
    return 0;
}