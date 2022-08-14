#include<bits/stdc++.h>
using namespace std;



bool hashPath(vector<vector<int>> & grid,vector<int>& start,vector<int>& dest){

    
}

int main(){

    vector<vector<int>> grid = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4} , destination = {4,4};
    cout<<hashPath(grid,start,destination);
    return 0;
}