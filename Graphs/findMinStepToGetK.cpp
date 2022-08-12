#include<bits/stdc++.h>
using namespace std;

int minStep(int start,int end, vector<int>& nums){

    vector<int> vis(end+1);
    queue<pair<int,int>>q;

    q.push({start,0});

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(node==end)  return steps;
        for(int i=0;i<nums.size();i++){

            int destination = node*nums[i];
            if(destination <= end && !vis[destination]){
                vis[destination] = 1;
                q.push({destination,steps+1});
            }
        }
    }
    return -1;
}

int main(){

    vector<int> nums = {2,3,5};

    cout<<minStep(2,100,nums);
}