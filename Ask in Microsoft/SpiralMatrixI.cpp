#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> & A){

    int r = A.size();
    int c = A[0].size();
    
    vector<int> ans;
    int row =0,col=0;

    while(row<r && col<c){

        if(row+1==r){

            for(int i=col;i<c;i++){
                ans.push_back(A[row][i]);
            }
            break;
        }

        if(col+1==c){

            for(int i=row;i<r;i++){
                ans.push_back(A[i][col]);
            }
            break;
        }

        int i;
        for(i = col;i<c;i++){
            ans.push_back(A[row][i]);
        }
        row++;
        for(i = row; i< r;i++){
            ans.push_back(A[i][c-1]);
        }
        c--;
        for(i=c-1;i>=col;i--){
            ans.push_back(A[r-1][i]);
        }
        r--;
        for(i = r-1;i>=row;i--){
            ans.push_back(A[i][col]);
        }
        col++;
    }
    return ans; 

}

int main(){

    vector<vector<int>> A={{1,2},{3,4},{5,6}};
    vector<int> ans= spiralOrder(A);
    for(auto i:ans){
        cout<<i<<" ";
    }           
    return 0;
}