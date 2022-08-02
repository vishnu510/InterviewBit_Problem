#include<bits/stdc++.h>
using namespace std;

int  findMax(vector<int>& nums,int k){

    int n = nums.size();

    if(n<k) return -1;

    int res = 0,i=0;
    while(i<k){
        res += nums[i++];
    }

    int currSum = res;

    for(int i=k;i<n;i++){

        currSum += nums[i] - nums[i-k];

        res = max(res,currSum);
    }
    return res;
}

int main(){

    vector<int> nums = {1,-4,2,8,6,-2,5};

    cout<<findMax(nums,8);
    return 0;
}