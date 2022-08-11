#include<bits/stdc++.h>
using namespace std;

int coutSubsetSumWithDiffK(vector<int> & nums,int diff){

    int n = nums.size();
    int s = 0;
    for(auto i:nums){
        s+=i;
    }
    int sum = (diff+s)/2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
            
        }
    }
    return dp[n][sum];
}

int main(){
    
    vector<int> nums = {1, 1, 2, 3 };
    cout<<coutSubsetSumWithDiffK(nums,2);
    return 0;
}