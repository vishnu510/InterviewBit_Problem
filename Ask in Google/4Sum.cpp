#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    set<vector<int>> store;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int newTarget = target -nums[i]-nums[j];
            int low =j+1,high = n-1;
            while(low<high){
                int sum = nums[low]+nums[high];
                if(sum>newTarget) high--;
                else if(sum<newTarget){
                    low++;
                }
                else{
                    store.insert({nums[i],nums[j],nums[low],nums[high]});
                    low++;
                    high--;
                }
            }
        }
    }
    for(auto i:store){
        ans.push_back(i);
    }
    return ans;
}

int main(){

    vector<int> nums ={1,0,-1,0,-2,2};
    vector<vector<int>> ans = fourSum(nums,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}