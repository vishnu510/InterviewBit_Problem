#include<bits/stdc++.h>
using namespace std;

int  MaxSumSubArray(vector<int>& nums,int k){

    int n = nums.size();
    int i=0,j=0;

    int sum =0,maxSum = INT_MIN;

    while (j<n)
    {
        sum  += nums[j];

        if((j-i+1) < k){
            j++;
        }
        else if((j-i+1)==k){
            maxSum = max(maxSum,sum);
            sum -= nums[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main(){

    vector<int> nums = {1,-4,-2,8,6,-2,5};

    cout<<MaxSumSubArray(nums,3);
    return 0;
}