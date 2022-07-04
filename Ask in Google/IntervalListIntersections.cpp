#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B){
    int i =0,j =0;
    vector<vector<int>> res;
    while(i<A.size()&&j<B.size()){
        int start = max(A[i][0],B[j][0]);
        int end = min(A[i][1],B[j][1]);
        if(start<=end){
            res.push_back({start,end});
        }
        if(A[i][1]<B[j][1]){
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

int main(){


    vector<vector<int>> A  = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B  = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> ans = intervalIntersection(A,B);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    return 0;
}