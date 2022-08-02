#include<bits/stdc++.h>
using namespace std;

int  findMax(vector<int>& nums,int k){

    int n = nums.size();

    int i=0,j=0;
    int mx = 0;
    vector<int> res;
    while(j-i!=k){
        mx+=nums[j];
        j++;
    }
    res.push_back(mx);
    for(;i<n-k+1;i++){

        mx-=nums[i];
        mx+=nums[j];
        res.push_back(mx);
        j++;
    }

    int ans = INT_MIN;
    for(auto i:res){
        ans = max(ans,i);
    }
    return ans;
}

int main(){

    vector<int> nums = {1,-4,2,8,6,-2,5};

    cout<<findMax(nums,3);
    return 0;
}