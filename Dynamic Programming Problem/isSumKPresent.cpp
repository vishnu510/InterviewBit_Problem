#include<bits/stdc++.h>
using namespace std;

bool isSumKPresent(vector<int> & nums, int sum){

    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int j=1;j<=sum;j++){
            dp[0][j] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] ||dp[i-1][j-nums[i-1]];
            }
            
        }
    }
    return dp[n][sum];
}

int main(){
    
    vector<int> nums = {2,0,7,8,10};
    cout<<isSumKPresent(nums,11);
    return 0;
}