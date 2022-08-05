#include<bits/stdc++.h>
using namespace std;

int  LongestSubArrSum(vector<int>& nums,int k){

    int n = nums.size();
    int j=0;

    int sum =0,count = 0;
    
    unordered_map<int,int> ump;

    for (;j<n;j++)
    {
        sum += nums[j];

        if(sum==k){
            count++;
        }

        if(ump.find(sum-k)!=ump.end()){
            count += ump[sum-k];
        }
        ump[sum]++;
    }
    return count;
}

int main(){

    vector<int> nums = {4,1,1,1,2,5};

    cout<<LongestSubArrSum(nums,5);
    return 0;
}