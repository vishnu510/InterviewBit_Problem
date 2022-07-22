#include<bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums){
    
    if(nums.size()==0 || nums[0].size()==0) return {};
    vector<int> res;
    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty())
    {
        auto x = q.front().first;
        auto y = q.front().second;
        res.push_back(nums[x][y]);

        if(x+1< nums.size() && y==0){
            q.push({x+1,y});
        }
        if(y+1 < nums[x].size()){
            q.push({x,y+1});
        }
        q.pop();
    }
    return res;

}
int main(){

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(nums);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}