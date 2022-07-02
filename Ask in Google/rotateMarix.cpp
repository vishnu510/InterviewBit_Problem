#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> rotate(vector<vector<int>> &A){
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(A[i][j],A[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(A[i].begin(),A[i].end());
    }
    return A;
}

int main(){

    vector<vector<int>> mat = {{1,2},{3,4}};
    vector<vector<int>> ans = rotate(mat);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}