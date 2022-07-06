#include<bits/stdc++.h>
using namespace std;

// Brute force

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> res;
        for(int itr = 0; itr <= nums.size()-k; itr++){
            int maxWindowValue = INT_MIN;
            for(int jtr = itr; jtr < itr+k; jtr++){
                maxWindowValue = max(maxWindowValue, nums[jtr]);
            }
            res.push_back(maxWindowValue);
        }
        return res;
}

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
    cout<<endl;
    vector<int> ans1 = maxSlidingWindow1(nums,3);
    for(auto it:ans1){
        cout<<it<<" ";
    }
    return 0;
}