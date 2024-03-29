#include<bits/stdc++.h>
using namespace std;

int getTarget(vector<int>& nums,int n,int sum){
    
    vector<vector<int>> dp(n+1,vector<int>(sum+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                dp[i][j] =0;
            }
            if(j==0){
                dp[i][j] =1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(nums[i-1] <= j){
                dp[i][j] =dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int targetSum(vector<int> & nums,int target){
    target = abs(target);
    int n = nums.size();
    int sum = 0;
    for(auto i:nums){
        sum+=i;
    }    
    if(sum < target || (sum+target)%2!=0){
        return 0;
    }
    sum = (sum+target)/2;

    return getTarget(nums,n,sum);
}

int main(){
    
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    cout<<targetSum(nums,1);
    return 0;
}