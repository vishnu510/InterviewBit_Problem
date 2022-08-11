#include<bits/stdc++.h>
using namespace std;

int MinimumSubsetSumDifference(vector<int> & nums){

    int n = nums.size();
    int sum = 0;
    for(auto i:nums){
        sum+=i;
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int j=1;j<=sum;j++){
            dp[0][j] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){

            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            if(nums[i-1] <=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    vector<int> res;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i]==true){
            res.push_back(i);
        }
    }
    int ans =INT_MAX;
    for(int i=0;i<res.size();i++){
        ans = min(ans,sum-2*res[i]);
    }
    return ans;
}

int main(){
    
    vector<int> nums = {1, 6, 11, 5 };
    cout<<MinimumSubsetSumDifference(nums);
    return 0;
}