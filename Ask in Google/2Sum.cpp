#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& nums, int target){
    int n = nums.size();
    vector<pair<int,int>> ans(n);
    for(int i=0;i<n;i++){
        ans.push_back({nums[i],i});
    }
    vector<pair<int,int>> res;
    int left =0,right =n-1;
    while(left<right){
        int sum = ans[left].first+ans[right].first;
        if(sum==target){
            res.push_back({ans[left].second,ans[right].second});
        }
        if(sum>target){
            right--;
        }
        else{
            left++;
        }
    }
    return {};
}

int main(){
    
    vector<int> nums ={2,7,11,15};
    vector<pair<int,int>> ans = twoSum(nums,9);
    for(auto i:ans){
        cout<<i.first<<" "<<i.second;
    }
    return 0;
}