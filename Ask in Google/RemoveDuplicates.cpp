#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums){
    if(nums.size()==0) return 0;
    int l = 0;
    for(int r=1;r<nums.size();r++){
        if(nums[l]!=nums[r]){
            l++;
            nums[l]  = nums[r];
        }
    }
    return l+1;
}

int main(){
    
    vector<int> nums ={1,1,2};
    cout<<removeDuplicates(nums);
    return 0;
}