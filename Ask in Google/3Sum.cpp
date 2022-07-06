#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(),nums.end());
    set<vector<int>> st;
    vector<vector<int>> ans;
    for(int i=0;i<nums.size();i++){
        ll l =i+1,r = nums.size()-1,sum=0;
        while(l<r){
            sum = (ll)nums[i]+nums[l]+nums[r];
            if(sum==0){
                st.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }
            if(sum>0){
                r--;
            }
            else{
                l++;
            }
        }
    }
    for(auto it=st.begin();it!=st.end();it++){
        ans.push_back(*it);
    }
    return ans;
}

int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);

    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    return 0;
}