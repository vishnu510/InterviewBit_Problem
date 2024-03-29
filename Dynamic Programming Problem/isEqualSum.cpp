#include<bits/stdc++.h>
using namespace std;

bool isEqualPartiotion(vector<int> & nums){

    int n = nums.size(), sum =0;
    for(auto i:nums){
        sum+=i;
    }    
    if(sum%2!=0) return false;

    vector<vector<int>> dp(sum/2+1,vector<int>(n+1));

    for(int i=0;i<=n;i++){
        dp[0][i] = true;
    }
    for(int i=1;i<=sum/2;i++){
        dp[i][0] = false;
    }

    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(nums[j-1] <= i){
                dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
            }
        }
    }
    return dp[sum/2][n];
}

int main(){
    
    vector<int> nums = {3, 1, 1, 2, 2, 1 };
    cout<<isEqualPartiotion(nums);
    return 0;
}