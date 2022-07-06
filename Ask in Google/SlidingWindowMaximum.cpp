#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        while (!dq.empty() && nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        while(!dq.empty() && i-dq.front()>k){
            dq.pop_front();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    
    vector<int> nums ={1,3,-1,-3,5,3,6,7};
    vector<int> ans = maxSlidingWindow(nums,3);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}